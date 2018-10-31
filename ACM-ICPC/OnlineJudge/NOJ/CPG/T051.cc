#include <stdio.h>
void Left(char *start, int a, char dist[]) {
  int flg = 0;
  int i = 0;
  while (1) {
    if (flg == a) {
      break;
    }
    dist[i++] = *start++;
    flg++;
  }
  dist[i] = '\0';
}
void Right(char *start, int a, char dist[]) {
  int i = 0;
  while (*++start)
    ;
  start -= a;
  while (*start) {
    dist[i++] = *start++;
  }
  dist[i] = '\0';
}
void Mid(char *start, int a, int b, char dist[]) {
  int i = 0;
  char *end = start;
  while (*++end)
    ;
  start += b;
  *(start + a) = '\0';
  while (dist[i++] = *start++)
    ;
  dist[i] = '\0';
}
int main() {
  char dist[50];
  char A[50];
  gets(A);
  int a, b;
  scanf("%d%d", &a, &b);
  Left(A, a, dist);
  printf("%s\n", dist);
  Right(A, a, dist);
  printf("%s\n", dist);
  Mid(A, a, b, dist);
  printf("%s\n", dist);
  return 0;
}