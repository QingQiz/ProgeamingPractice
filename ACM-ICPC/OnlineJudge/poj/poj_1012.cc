#include <iostream>
using namespace std;

int ans[14];
void getans(){
    for(int i=1;i<14;i++){
        for(int j=i+1;;j++){
            int sum=2*i;
            for(int mid=j;;mid+=j-1){
                mid=mid%sum?mid%sum:sum;
                if(mid<=i)break;
                sum--;
                if(sum==i){
                    ans[i]=j;
                    goto L;
                }

            }
        }
L:;
    }
}

int main(){
    getans();
    int k;
    while (cin >> k && k) {
        cout << ans[k] << endl;
    }
    return 0;
}

//------------------------------------------------------------------------
//https://vjudge.net/contest/205705#problem/R
//
//有两种思路
//第一，用一个暴力的算法列出所有答案，用另一个程序来接收这些答案，简单AC
//
//第二，事先打表，直接输出
//          打表思路：
//          对于每一个k来说最多删k次，如果删的第i个人的编号小于k，则这种
//          方案不可取，第一次删的元素是第j，第二次删的元素是第(j+j-1)%sum
//          个，一共删k次，即最后剩余k个元素，则方案成立           ^
//                                                                <|>
//                                                                 |
//                                                                 |
//                                                                 |
//                                              因为删除一个以后，mid所指
//                                              的位置是所删除元素的下一个
//                                              元素,比如1.2.3.4,删除3,则3
//                                              的位置变成3的下一个元素4,所
//                                              以，每次删除以后加j-1
//-------------------------------------------------------------------------
