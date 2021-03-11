/* Captain Jack Sparrow
 * Convert Integer to Roman Number
 * TODO: Make it more algorithmic
 * */
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// #define MAX 3999

char* digit2str(int n, int *len);

int main(int argc, char *argv[]) {
  int num;
  scanf("%d", &num);
  char roman[20], pos = 0;
  if (num > MAX) {
    printf("ERROR: Max limit exceeded %d.\n", MAX);
    return 1;
  }
  int power = 1;
  int tmp = num / 10;
  while (tmp) {
    power *= 10;
    tmp /= 10;
  }
  // printf("%d\n", power);
  while (num) {
    char* ttt = digit2str((num/power)*power, &tmp);
    for (i=0; i<tmp; i++) {
      roman[pos++] = ttt[i];
    }
    num = num - (num/power)*power;
    power = power / 10;
    //printf("num = %d, pow = %d\n", num, power);
  }
  roman[pos] = '\0';
  printf("%s\n", roman);
  return 0;
}

char* digit2str(int n, int *len) {
  switch (n) {
    case 1:    *len = 1; return "I";
    case 2:    *len = 2; return "II";
    case 3:    *len = 3; return "III";
    case 4:    *len = 2; return "IV";
    case 5:    *len = 1; return "V";
    case 6:    *len = 2; return "VI";
    case 7:    *len = 3; return "VII";
    case 8:    *len = 4; return "VIII";
    case 9:    *len = 2; return "IX";
    case 10:   *len = 1; return "X";
    case 20:   *len = 2; return "XX";
    case 30:   *len = 3; return "XXX";
    case 40:   *len = 2; return "XL";
    case 50:   *len = 1; return "L";
    case 60:   *len = 2; return "LX";
    case 70:   *len = 3; return "LXX";
    case 80:   *len = 4; return "LXXX";
    case 90:   *len = 2; return "XC";
    case 100:  *len = 1; return "C";
    case 200:  *len = 2; return "CC";
    case 300:  *len = 3; return "CCC";
    case 400:  *len = 2; return "CD";
    case 500:  *len = 1; return "D";
    case 600:  *len = 2; return "DC";
    case 700:  *len = 3; return "DCC";
    case 800:  *len = 4; return "DCCC";
    case 900:  *len = 2; return "CM";
    case 1000: *len = 1; return "M";
    case 2000: *len = 2; return "MM";
    case 3000: *len = 3; return "MMM";
    default: *len = 0; return "\0";
  }
}