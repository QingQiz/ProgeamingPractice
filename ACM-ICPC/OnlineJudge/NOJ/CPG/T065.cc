#include <stdio.h>
struct info {
    long no;
    char A[10];
    int age;
    double grade[7];
};
int main()
{
    double ave[10];
    for (int i = 0; i < 10; i++)ave[i]=0; 
    struct info student[10],u;
    for (int i = 0; i < 10; i++) {
        scanf("%ld",&student[i].no);
        scanf("%s",student[i].A);
        scanf("%d",&student[i].age);
        for (int j = 0; j < 7; j++) {
            scanf("%lf",&student[i].grade[j]);   
            ave[i]+=student[i].grade[j]/7;
        }
    }
    int i=0,k=1;
    for (;k < 10; k++) {
        if(ave[i]<ave[k])i=k;
    }
    u=student[i];
    printf("%ld %s %d ",u.no,u.A,u.age);
    for (int i = 0; i < 6; i++) {
        printf("%.2lf ", u.grade[i]);
    }
    printf("%.2lf",u.grade[6]);
    return 0;
}