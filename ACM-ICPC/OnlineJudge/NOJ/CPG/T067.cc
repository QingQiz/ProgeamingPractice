#include <stdio.h>
#include <stdlib.h>
struct data {
  int no;
  char name[12];
  int grade;
};
int main() {
  int N;
  scanf("%d", &N);
  struct data *p;
  p = (struct data *)malloc(N * sizeof(struct data));
  for (int i = 0; i < N; i++) {
    scanf("%d%s%d", &(p + i)->no, (p + i)->name, &(p + i)->grade);
  }
  FILE *pt;
  pt = fopen("DATA5614.DB", "w");
  if (pt != NULL) {
    for (int i = 0; i < N; i++) {
      fprintf(pt, "%d %s %d\n", (p + i)->no, (p + i)->name, (p + i)->grade);
    }
  }
  fclose(pt);
  pt = fopen("DATA5614.DB", "r");
  if (pt == NULL) return -1;
  struct data *q;
  q = (struct data *)malloc(N * sizeof(struct data));
  if (!feof(pt)) {
    for (int i = 0; i < N; i++) {
      fscanf(pt, "%d %s %d", &(q + i)->no, (q + i)->name, &(q + i)->grade);
    }
  }
  int k = 0;
  for (int j = 1; j < N; j++) {
    if ((q + j)->grade > (q + k)->grade) k = j;
  }
  q += k;
  printf("%d %s %d", q->no, q->name, q->grade);
  return 0;
}