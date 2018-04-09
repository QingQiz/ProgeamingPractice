#include <stdio.h>
typedef struct XY
{
    int x,y;
}XY;

int main()
{
    XY p[3],a1,a2;
    for(int i=0;i<3;i++)scanf("%d%d",&p[i].x,&p[i].y);
    a1.x=p[2].x-p[0].x,a1.y=p[2].y-p[0].y;
    a2.x=p[1].x-p[0].x,a2.y=p[1].y-p[0].y;
    if(a1.x*a2.y-a2.x*a1.y<0)printf("0");
    else printf("1");
    return 0;
}