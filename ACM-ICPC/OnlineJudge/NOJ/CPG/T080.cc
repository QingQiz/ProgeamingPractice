#include <stdio.h>
#include <stdlib.h>
typedef struct LinkList {
  int no;
  struct LinkList* next;
} NODE;

void DestroyList(NODE* L);
void display(NODE* L);

int main() {
  NODE *p, *s, *L, *q;
  int number;
  scanf("%d", &number);
  L = (NODE*)malloc(sizeof(NODE));
  L->next = NULL;
  p = L;
  while (number > 0) {
    s = (NODE*)malloc(sizeof(NODE));
    scanf("%d", &s->no);
    p->next = s, p = s;
    p->next = NULL;
    number--;
  }

  for (q = L->next; q->next != NULL; q = q->next) printf("%d ", q->no);
  printf("%d", q->no);

  q = L->next;
  while (q != NULL) {
    p = q->next;
    free(q);
    q = p;
  }
  return 0;
}