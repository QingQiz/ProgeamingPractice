#include <bits/stdc++.h>
int f[1200];  

int main(){  
    int a,b,n;  
    int i, j;  
    int flag, term, begin;  
    while(~scanf("%d%d%d", &a, &b, &n) && (a||b||n)){  
        memset(f, 0, sizeof(f));  
        f[1]=1;  
        f[2]=1;  
        term = n;  
        flag = 0;  
        for(i=3; i<=n&&!flag; i++){  
            f[i] = (a*f[i-1]+b*f[i-2])%7;  
            for(j = 2; j<i; j++){  
                if(f[i]==f[j]&&f[i-1]==f[j-1]){  
                    term = i-j;  
                    begin = j-2;  
                    flag = 1;  
                    break;  
                }  
            }  
        }  
        std::cout << term << std::endl;
        if(flag)  
            printf("%d\n", f[begin+(n-1-begin)%term+1]);  
        else  
            printf("%d\n", f[n]);  
    }  
    return 0;  
}  

