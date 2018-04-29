#include <bits/stdc++.h>
#define SETZ(_) \
    for(int i=0;i<N;i++)\
        _[i].color="_______",\
        _[i].num=0
struct excu{
    std::string color;
    int num;
};
int find(excu aim[],std::string cmp,int n){
    for(int i=0;i<n;i++)
        if(aim[i].color==cmp)
            return i;
    return -1;
}
int main(int argc, char const* argv[])
{
    using namespace std;
    int N;
    while(1){
        cin >> N;
        if(N==0)break;
        excu aim[1000];
        SETZ(aim);
        string cmp;
        int num,cont=0;
        for(int i=0;i<N;i++){
            cin >> cmp;
            num=find(aim,cmp,N);
            if(num!=-1)
                aim[num].num++;
            else
                aim[cont].color=cmp,
                aim[cont++].num=1;
        }
        excu max;
        max.num=0;
        for(int i=0;i<N;i++)
            if(max.num<aim[i].num)
                max=aim[i];
        cout << max.color << endl;
    }
    return 0;
}

