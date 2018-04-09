#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const* argv[])
{
    int n,m;
    while (cin >> n >> m) {
        m--;
        int *data=new int[n];
        for(int i=1;i<=n;i++)data[i-1]=i;
        while(m--)
            next_permutation(data,data+n);
        for(int i=0;i<n;i++){
            if(i)cout << ' ';
            cout << data[i];
        }
        cout << endl;
        delete [] data;
    }
    return 0;
}

//算法库中的next_permutation 是生成下一个较大的排列（字母序）直到降序
//prev_permutation 生成下一个较小排序，直到升序
//https://vjudge.net/contest/205705#problem/K
