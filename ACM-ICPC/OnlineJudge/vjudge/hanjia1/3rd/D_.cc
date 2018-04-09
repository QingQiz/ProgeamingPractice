//#include <bits/stdc++.h>   
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int> q;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m,n;
        cin >> m >> n;
        int *tempu = new int [n];
        int *tempd = new int [n];
        for(int i = 0; i < n; ++i)
            cin >> tempu[i];
        sort(tempu, tempu + n);
        for(int i = 0; i < m - 1; ++i) {
            while(!q.empty())q.pop();
            for(int j = 0; j < n; j++)
                cin >> tempd[j];
            sort(tempd, tempd + n);
            for(int k = 0; k < n; ++k){
                for(int p = 0; p < n; ++p){
                    int mid = tempu[k] + tempd[p];
                    if((int)q.size() < n)
                        q.push(mid);
                    else {
                        if(mid < q.top()){
                            q.pop();
                            q.push(mid);
                        }
                    }
                }
            }
            for(int k = n-1; k >= 0; --k){
                tempu[k] = q.top();
                q.pop();
            }
        }
        for(int i = 0; i < n; ++i) {
            if(i) cout << ' ';
            cout << tempu[i];
        }
        cout << endl;
        delete [] tempu;
        delete [] tempd;
    }
    return 0;
}

//https://vjudge.net/contest/205707#problem/D
//贪心
//前k个序列的前n小值可以由前k-1个序列的前n小值和第k个序列得到
//以为第前k个序列的第二小值,或者是前k-1个序列的最小值加第k个序列的第二小值,或者相反
//
//贪心证明:
//
