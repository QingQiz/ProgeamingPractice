#include <iostream>

int findans(int,int[]);
int main(int argc, char const* argv[])
{
    int T,ANS[100],cont=0;
    std::cin >> T;
    while(T--){
        int n;
        std::cin >> n;
        int use[n];
        for(int i=0;i<n;i++)
            std::cin >> use[i];
        ANS[cont++]=findans(n,use);
    }
    for(int i=0;i<cont;i++){
        std::cout << "case #" << i+1 
                  << ": "     << ANS[i]
                  <<std::endl;
    }
    return 0;
}

int findans(int n,int use[]){
    int min=use[0],k=0,sum=0;
    for(int i=0;i<n;i++)
        if(min>=use[i])min=use[i],k=i;
    while(1){
        k=(k+1)%n;
        if(use[k]==0)break;
        use[k]--;
        sum++;
    }
    return sum;
}
