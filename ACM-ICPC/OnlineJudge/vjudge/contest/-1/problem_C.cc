#include <iostream>

#define DISTANCE(a,b) (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)
#define JUDGE(a,b,c,d,e,f) ((4*a*b*c*d)==(e*f-a*c-b*d)*(e*f-a*c-b*d))

#define DEFINE(coo,nu0,nu1,nu2,nu3,ans) \
    a=DISTANCE(coo[nu0],coo[nu1]);\
    b=DISTANCE(coo[nu1],coo[nu2]);\
    c=DISTANCE(coo[nu2],coo[nu3]);\
    d=DISTANCE(coo[nu3],coo[nu0]);\
    e=DISTANCE(coo[nu0],coo[nu2]);\
    f=DISTANCE(coo[nu1],coo[nu3]);\
    ans=JUDGE(a,b,c,d,e,f);

struct coordinate{
    int x,y;
};
int judge(coordinate aim[]);
int main(int argc, char const* argv[])
{
    int T,ANS[100],cont=0;
    std::cin >> T;
    while(T--){
        coordinate aim[5];
        for(int i=0;i<5;i++)
            std::cin >> aim[i].x >> aim[i].y;
        ANS[cont++]=judge(aim);
    }
    for (int i = 0; i < cont; i++)
        if(ANS[i])
            std::cout << "case #" << i+1 << ' '
                      << "Yes"    << std::endl;
        else
            std::cout << "case #" << i+1 << ' '
                      << "No"     << std::endl;
    return 0;
}

int judge(coordinate aim[]){
    int a,b,c,d,e,f;
    int ans1,ans2;
    DEFINE(aim,0,1,2,3,ans1)
    DEFINE(aim,0,1,2,4,ans2)
    return ans1 & ans2;
}

