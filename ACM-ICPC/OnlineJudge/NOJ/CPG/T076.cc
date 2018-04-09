#include <stdio.h>
#include <stdlib.h>
typedef struct LinkList{
    int no;
    char name[12];
    int age;
    struct LinkList* next;
}NODE;

void ListDelete(NODE* L,int n);
void DestroyList(NODE* L);
void display(NODE* L);

int main()
{

    NODE *p,*s,*L;
    int number;
    L=(NODE*)malloc(sizeof(NODE));
    L->next=NULL;
    p=L;
    while(1){
        scanf("%d",&number);
        if(number==0)break;
        s=(NODE*)malloc(sizeof(NODE));
        s->no=number;
        scanf("%s",s->name);
        scanf("%d",&s->age);
        p->next=s,p=s;
        p->next=NULL;
    }
    int m;
    scanf("%d",&m);
    display(L);
    putchar('\n');
    ListDelete(L,m);
    display(L);
    DestroyList(L);
    return 0;
}

void ListDelete(NODE *L,int n)
{
    NODE *p,*q;
    q=L;
    while(q!=NULL){
        p=q;
        q=q->next;
        if(q->no==n)break;
    }
    p->next=q->next;
    free(q);
}

void DestroyList(NODE *L)
{
    NODE *q,*p;
    p=L;
    q=p->next;
    while(q!=NULL){
        free(q);
        q=p->next->next;
        p=p->next;
    }
}

void display(NODE *L)
{
    NODE *q;
    for(q=L->next;q->next!=NULL;q=q->next)
        printf("%d ",q->no);
    printf("%d",q->no);
}