/* Captain Jack Sparrow
 * Convert Roman Numbers to Integers
 * */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int char2int(char c) {
  switch (c) {
    case 'i':
    case 'I': return 1;
    case 'v':
    case 'V': return 5;
    case 'x':
    case 'X': return 10;
    case 'l':
    case 'L': return 50;
    case 'c':
    case 'C': return 100;
    case 'd':
    case 'D': return 500;
    case 'm':
    case 'M': return 1000;
    default: return 0;
  } 
}

bool validateDigits(int digits[], int len) {
  // TODO: Validate digits
  // THe Decision is ambiguous
  // Subtractive form
  // Additive form
  // Irregular subtraction notation
  // etc...
  return true;
}

int roman2int(char roman[], int len) {
  if (len == 0) return 0;
  int res = 0;
  int digits[len];
  for (int i = 0; i < len; i++) {
    digits[i] = char2int(roman[i]);
    if (digits[i] == 0) return -1;
  }
  if (!validateDigits(digits, len)) return -2;
  for (int i = 0; i < len - 1; i++) {
    res += digits[i] >= digits[i+1] ? digits[i] : -digits[i];
  }
  res += digits[len-1];
  return res;
}

int main(int argc, char *argv[]) {
  char roman[20];
  scanf("%s", roman);
  int len = strlen(roman);
  // printf("%s, %d\n", roman, len);
  int value = roman2int(roman, len);
  if (value == -1) {
    printf("Error: Contains Invalid Characters\n");
  } else if (value == -2) {
    printf("Error: Invalid Roman Number\n");
  } else {
    printf("%d\n", value);
  }
  return 0;
}