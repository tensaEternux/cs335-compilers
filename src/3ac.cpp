#include <fstream>
#include "3ac.h"
#include "typeCheck.h"
using namespace std;
using std::setw;

map<int , string> gotoLabels;
ofstream intermediateCodeFile;
long long Index = -1;
map<string, int> gotoIndex;
unordered_map<string, list<int>> gotoIndexPatchList;

vector <quad> emittedCode;
string getTmpVar() {
  static long a = 0;
  a += 1;
  string tmp =  string("__t") + to_string(a) + string("__");
  return tmp;
}

pair<string, sEntry*> getTmpSym(string type) {
  string tmp = getTmpVar();
  char *cstr = new char[type.length() + 1];
  strcpy(cstr, type.c_str());
  insertSymbol(*curr, tmp, type, getSize(cstr),0, 1);
  return pair <string, sEntry* >(tmp, lookup(tmp));
}

int emit (qid op, qid id1, qid id2, qid  res, int stmtNum) {
  quad t;
  t.op = op;
  t.id1 = id1;
  t.id2 = id2;
  t.res = res;
  t.stmtNum = stmtNum;
  emittedCode.push_back(t);
  Index++;
  return emittedCode.size()-1;
}

int getNextIndex() {
  return emittedCode.size();
}

void backPatch(list<int> li, int p) {
  for (int i=0; i<li.size(); i++) {
    if (li.size() > i) {
      std::list<int>::iterator it = li.begin();
      std::advance(it, i);
      emittedCode[*it].stmtNum = p;
    }
  }
}

void setResult(int a, qid p) {
  emittedCode[a].res = p;
}

void setId1(int a, qid p) {
  emittedCode[a].id1 = p;
}


void setListId1(list<int> li, qid p){
  for (int i=0; i<li.size(); ++i) {
    if (li.size() > i) {
      std::list<int>::iterator it = li.begin();
      std::advance(it, i);
      setId1(*it, p);
    }
  }
}

int assignmentExpression(char *o, string type, string type1, string type3, qid place1, qid place3) {
  qid t1 = place3, t2;
  string op, op1;
  int a=0, b=0, k;
  if (!strcmp(o,"=")) a = 1;
  if (!strcmp(o,"*=")) {
    op = "*";
    op1 = "*";
    t1 = getTmpSym(type);
  } else if (!strcmp(o,"/=")) {
    op = "/";
    op1 = "/";
    t1 = getTmpSym(type);
  } else if (!strcmp(o,"+=")) {
    op = "+";
    op1 = "+";
    t1 = getTmpSym(type);
  } else if (!strcmp(o,"-=")) {
    op = "-";
    op1 = "-";
    t1 = getTmpSym(type);
  }
  if (isInt(type1) && isInt(type3)) {
    op += "int";
    if (strcmp(o,"="))
      k = emit(pair<string, sEntry*>(op, lookup(op1)), place1, place3, t1, -1);
  } else if (isFloat(type1) && isInt(type3)) {
    t2 = getTmpSym(type);
    k = emit(pair<string, sEntry*>("inttoreal",NULL), place3,pair<string, sEntry*>("",NULL),t2,-1);
    op += "real";
    if (strcmp(o,"="))
      emit(pair<string, sEntry*>(op, lookup(op1)), place1, t2, t1, -1);
    b = 1;
  } else if (isFloat(type3) && isInt(type1)) {
    t2 = getTmpSym(type);
    k = emit(pair<string, sEntry*>("realtoint",NULL),place3,pair<string, sEntry*>("",NULL),t2,-1);
    op += "int";
    if(strcmp(o,"="))
      emit(pair<string, sEntry*>(op, lookup(op1)), place1, t2, t1, -1);
    b = 1;
  } else if (isFloat(type3) && isFloat(type1)) {
    op += "real";
    if (strcmp(o,"=")) 
    k = emit(pair<string, sEntry*>(op, lookup(op1)), place1, place3, t1, -1);
  }

  if (!(a &&b ))
    k = emit(pair<string, sEntry*>("=", lookup("=")),  t1, pair<string, sEntry*>("", NULL), place1, -1);
  else 
    emit(pair<string, sEntry*>("=", lookup("=")),  t2, pair<string, sEntry*>("", NULL), place1, -1);

  return k;
}

void assignment2(char *o, string type, string type1, string type3, qid place1, qid place3) {
  qid t = getTmpSym(type);
  string op, op1;
  if      (!strcmp(o,"%=")) op = "%";
  else if (!strcmp(o,"^=")) op = "^";
  else if (!strcmp(o,"|=")) op = "|";
  else if (!strcmp(o,"&=")) op = "&";
  op1 = op;
  if (!strcmp(o,"<<=")) { op="LEFT_OP";  op1="<<"; }
  if (!strcmp(o,">>=")) { op="RIGHT_OP"; op1=">>"; }
  emit(pair<string, sEntry*>(op, lookup(op1)), place1, place3, t, -1);
	emit(pair<string, sEntry*>("=", lookup("=")),  t, pair<string, sEntry*>("", NULL), place1, -1);
}

bool gotoIndexStorage (string id, int loc) {
  if (gotoIndex.find(id) == gotoIndex.end()) {
    gotoIndex.insert(pair<string, int>(id, loc));
    return true;
  }
  return false;
}

void gotoIndexPatchListStorage (string id, int loc) {
  gotoIndexPatchList[id].push_back(loc);
}

char* backPatchGoto() {
  for (auto it = gotoIndexPatchList.begin(); it!=gotoIndexPatchList.end(); ++it){
    if(gotoIndex.find(it->first)==gotoIndex.end()){
      char *a;
      strcpy(a, it->first.c_str());
      return a;
    } else {
      backPatch(gotoIndexPatchList[it->first] , gotoIndex[it->first]);
    }
  }
  return NULL;
}

void display3ac() {
  intermediateCodeFile.open("intermediateCode.txt");
  for(int i = 0; i<emittedCode.size(); ++i)  {
    display(emittedCode[i], i);
  }
  intermediateCodeFile.close();
}


void display(quad q, int i) {
  int k;
  if (q.stmtNum==-1 || q.stmtNum == -4) {
    intermediateCodeFile << setw(5) << "[" << i << "]" << ": " << setw(15) << q.op.first << " " <<
      setw(15) << q.id1.first << " " <<
      setw(15) << q.id2.first << " " <<
      setw(15) << q.res.first << '\n';
  } else if (q.stmtNum==-2 || q.stmtNum == -3) {
    intermediateCodeFile  << endl << "[" << i << "]" << ": "<<
    q.op.first << endl << endl;
  } else {
    k = q.stmtNum;
    while(emittedCode[k].op.first == "GOTO" && emittedCode[k].id1.first == ""){
      k = emittedCode[k].stmtNum;
    } 
      
    if (gotoLabels.find(k)== gotoLabels.end()) 
      gotoLabels.insert(pair<int, string>(k, "Label"+to_string(k)));
    intermediateCodeFile << setw(5) << "[" << i << "]" << ": " << setw(15) << q.op.first << " " <<
      setw(15) << q.id1.first << " " <<
      setw(15) << q.id2.first << " " <<
      setw(15) << k << "---" << '\n';
    emittedCode[i].stmtNum = k;
  }
}
