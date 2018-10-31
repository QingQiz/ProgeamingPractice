#include <stdio.h>
#include <string.h>
int main() {
  char A[2][6];
  scanf("%s", A[0]);
  scanf("%s", A[1]);
  char Co[10][3] = {"A#", "Bb", "C#", "Db", "D#", "Eb", "F#", "Gb", "G#", "Ab"};
  int i;
  for (i = 0; i < 10; i++) {
    if (strcmp(A[0], Co[i]) == 0 && i % 2 == 0) {
      A[0][0] = Co[i + 1][0];
      A[0][1] = Co[i + 1][1];
      break;
    }
    if (strcmp(A[0], Co[i]) == 0 && i % 2 != 0) {
      A[0][0] = Co[i - 1][0];
      A[0][1] = Co[i - 1][1];
      break;
    }
  }
  printf("%s %s", A[0], A[1]);
  return 0;
}