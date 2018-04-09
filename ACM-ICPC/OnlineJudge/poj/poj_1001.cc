#include <iostream>
#include <cstring>
using namespace std;
#define maxn 200
int ans[maxn];

void prower(int bal,int index){
    memset(ans,0,sizeof(ans));
    ans[maxn-1]=1;
    while(index--){
        for(int j=maxn-1;j>=0;j--){
            ans[j]*=bal;
        }
        for(int k=maxn-1;k>=0;k--){
            ans[k-1]+=ans[k]/10;
            ans[k]%=10;
        }
    }
}

int main(){
    char in[7];
    int index;
    while (scanf("%s%d",in,&index)==2) {
        int len=strlen(in);
        char rel[6];memset(rel,0,sizeof(rel));

        if(strcmp(in,"0")==0){
            cout << '0' << endl;
            continue;
        }

        for(int i=len-1;i>=0;i--){
            if(in[i]=='0')in[i]='\0';
            else break;
        }
        
        int num=0,cnt=0;
        len=strlen(in);
        for(int i=0;i<len;i++){
            if(in[i]=='.'){
                num=len-i-1;
                continue;
            }
            rel[cnt++]=in[i];
        }
        num*=index;
        int bal=atoi(rel);
        prower(bal,index);
        int i=0;
        while(ans[i++]==0){
            if(maxn-i==num-1)break;
        }i--;
        for(;i<maxn;i++){
            if(maxn-i==num)cout << '.';
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205705#problem/Q
//精确乘幂，
//先视为整数
//记录小数点位置，注意数组下表
//注意数组初始化
//注意数组初始化
//注意数组初始化
//注意数组初始化
//注意数组初始化
//注意数组初始化
//注意数组初始化
