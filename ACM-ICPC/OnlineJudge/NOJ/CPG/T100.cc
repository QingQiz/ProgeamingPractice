#include <stdio.h>
#include <stdlib.h>

int main(){
    long long male[100]={0},famale[100]={0},m_sum,f_sum,mid;
    int n,cont=0;
    while(scanf("%d",&n)==1&&n!=-1){
        m_sum=1,f_sum=0;
        for(int i=1;i<n;i++){
            mid=f_sum;
            f_sum=m_sum;
            m_sum+=mid+1;
        }
        male[cont]=m_sum,famale[cont++]=f_sum;
    }
    for(int i=0;i<cont;i++)printf("%lld %lld\n",male[i],male[i]+famale[i]+1);
    return 0;
}