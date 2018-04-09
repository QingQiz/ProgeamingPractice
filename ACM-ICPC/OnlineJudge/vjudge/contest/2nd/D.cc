#include <iostream>
using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
        char *data=new char[2*n+1];
        bool *live=new bool[2*n+1];
        for(int i=1;i<=2*n;i++){
            data[i]='G';
            live[i]=true;
        }
        int sum=0;
        int k=1;
        while(sum!=n){
            for(int i=1;i<=2*n;i++){
                if(sum==n)break;
                if(live[i]==false)
                    continue;
                if(k%m==0){
                    data[i]='B';
                    live[i]=false;
                    sum++;
                }
                k++;
            }
        }
        for(int i=1;i<=2*n;i++){
            cout << data[i];
            if(i%50==0)cout << endl;
        }
        cout << "\n\n";
        delete [] data;
        delete [] live;
    }
    return 0;
}
