#include <stdio.h>
#include <string.h>
void change(char All[], char find[], char aim[], int lenAll, int lenfind) {
  int k, flg, i, j;
  while (1) {
    for (i = 0; i <= lenAll - lenfind; i++) {
      k = i;
      flg = 0;
      for (j = 0; j < lenfind; j++) {
        if (All[k] == find[j]) flg++;
        k++;
      }
      if (flg == lenfind) break;
    }
    if (flg != lenfind) goto end;
    char A[80], B[80], C[80];
    for (int j = 0; j < i; j++) A[j] = All[j];
    A[i] = '\0';
    for (int j1 = 0, j2 = i; j1 < flg; j1++, j2++) B[j1] = All[j2];
    B[flg] = '\0';
    for (int j1 = 0, j2 = i + flg;; j1++, j2++) {
      C[j1] = All[j2];
      if (C[j1] == '\0') break;
    }
    for (int i = 0;; i++) {
      B[i] = aim[i];
      if (B[i] == '\0') break;
    }
    strcat(A, B);
    strcat(A, C);
    for (int i = 0;; i++) {
      All[i] = A[i];
      if (All[i] == '\0') break;
    }
  }
end:;
}
int main() {
  char A[80], B[80], C[80];
  gets(A);
  gets(B);
  gets(C);
  int a = strlen(A), b = strlen(B);
  change(A, B, C, a, b);
  printf("%s\n", A);
  return 0;
}