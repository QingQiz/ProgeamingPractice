//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <set>
using namespace std;
bool book[1000010];
int data[310];

int main(int argc, char const* argv[])
{
    int T;cin >> T;
    while (T--) {
        int n,i;cin >> n;
        for(i=0;i<n;i++)
            cin >> data[i];
        for (i = n;; i++) {
            int flg=1;
            memset(book,false,i*sizeof(book[0]));
            for(int j=0;j<n;j++){
                if(book[data[j]%i]){
                    flg=0;
                    break;
                }
                book[data[j]%i]=true;
            }
            if(flg)break;
        }
        cout << i << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205705#problem/P
//------------------------------------------------------------------
//很那啥的题，无限超时，                                           |
//------------------------------------------------------------------
//memset的技巧                                                     |
//对于modx来说，只需要x个数便能表示modx下的运算                    |
//因此，memset只需要x个单位即可，不然就是在浪费时间                |
//                                                                 |
//memset的技巧                                                     |
//memset的技巧                                                     |
//memset的技巧                                                     |
//------------------------------------------------------------------
//本来是想用set的没有重复元素的性质做，但是insert有点浪费时间      |
//然后学习到了一种类似桶排序的查重方法                             |
//                                                                 |
//桶排序查重                                                       |
//桶排序查重                                                       |
//桶排序查重                                                       |
//------------------------------------------------------------------
