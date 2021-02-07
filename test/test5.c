/* Captain Jack Sparrow
 * Frequency Analysis Tool
 * */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**  Global Variables  **/

char color[][6] = {
  "\e[39m", // default
  "\e[91m", // light red
  "\e[31m", // red
  "\e[32m", // green
};

/**  Define Structures  **/

struct item {
  int c; // char 0-25
  int count;
  int total;
  int possible[5]; // possible chars
  int poss_len;
};
typedef struct item item;

struct history {
  int from; // char from
  int to;   // char to
  int pos[500]; // positions
  int pos_len;
};
typedef struct history history;

struct color_char {
  char c;
  char i;
};
typedef struct color_char color_char;

/**  Initialize Structures  */

void init_item(item *i) {
  i->poss_len = 0;
}

void init_history(history *h) {
  h->pos_len = 0;
}

/**  Print Interactive Output  **/

void print(color_char msg[], item items[], history hist[], int hist_len) {
  printf("\nProgress: ");
  int i=0;
  while (true) {
    if (msg[i].c == '\0') break;
    printf("%s%c", color[msg[i].i], msg[i].c);
    i++;
  }
  printf("\n\n");
  for (int i=0; i<26; i++) {
    printf("%c (%2d/%d) -> ", items[i].c + 'A', items[i].count, items[i].total);
    for (int j=0; j<items[i].poss_len; j++) {
      printf("%c", items[i].possible[j] + 'a');
    }
    if ((i+1) % 6 == 0) printf("\n");
    else printf("    ");
  }
  printf("\n\n");
}

int main() {
  // --- Variables ---
  item items[26];
  history his[26];
  int his_pos = 0;
  color_char msg[1500];
  int len = 0;
  // --- message input ---
  printf("Message: ");
  while (true) {
    char c = getchar();
    if (c == '\n' && len > 0) {
      msg[len].c = '\0';
      msg[len].i = 0;
      break;
    } else {
      msg[len].c = c;
      msg[len++].i = 0;
    }
  }
  // --- initialize items ---
  int total = 0, chrs[26];
  for (int i=0; i<26; i++) {
    chrs[i] = 0;
  }
  for (int i=0; i<len; i++) {
    char c = msg[i].c;
    if (c >= 'a' && c <= 'z') {
      chrs[c-'a']++;
      total++;
    } else if (c >= 'A' && c <= 'Z') {
      chrs[c-'A']++;
      total++;
    }
  }
  for (int i=0; i<26; i++) {
    int max = chrs[0], pos = 0;
    for (int j=1; j<26; j++) {
      if (chrs[j] > max) {
        max = chrs[j];
        pos = j;
      }
    }
    items[i].c = pos;
    items[i].count = max;
    items[i].total = total;
    chrs[pos] = -1;
  }
  // --- play game ---
  char c1, c2;
  while (true) {
    print(msg, items, his, his_pos);
    printf("Make a move : ");
    scanf("%c", &c1);
    if (c1 == '0') {
      break;
    } else if (c1 == '-') {
      if (his_pos == 0) continue;
      his_pos--;
      char from = his[his_pos].from;
      char to = his[his_pos].to;
      for (int i=0; i<26; i++) {
        if (items[i].c == from) {
          items[i].poss_len = 0;
        }
      }
      for (int i=0; i<his[his_pos].pos_len; i++) {
        int pos = his[his_pos].pos[i];
        if (msg[pos].c >= 'a' && msg[pos].c <= 'z') {
          msg[pos].c = from + 'a';
        } else {
          msg[pos].c = from + 'A';
        }
        msg[pos].i = 0;
      }
    } else if (c1 >= 'a' && c1 <= 'z') {
      printf("TO: ");
      c2 = getchar();
      while (!(c2 >= 'a' && c2 <= 'z')) {
        c2 = getchar();
      }
      c1 -= 'a'; c2 -= 'a';
      for (int i=0; i<26; i++) {
        if (items[i].c == c1) {
          if (items[i].poss_len >= 1) {
            printf("already done.\n");
          } else {
            items[i].possible[0] = c2;
            items[i].poss_len = 1;
            his[his_pos].from = c1;
            his[his_pos].to = c2;
            for (int j=0; j<len; j++) {
              if (msg[j].i == 1) {
                msg[j].i = 3;
              }
              if (msg[j].i == 0) {
                if (msg[j].c == c1+'a') {
                  msg[j].c = c2 + 'a';
                  msg[j].i = 1;
                  his[his_pos].pos[his[his_pos].pos_len++] = j;
                } else if (msg[j].c == c1+'A') {
                  msg[j].c = c2 + 'A';
                  msg[j].i = 1;
                  his[his_pos].pos[his[his_pos].pos_len++] = j;
                }
              }
            }
            his_pos++;
          }
        }
      }
    }
  }
  return 0;
}