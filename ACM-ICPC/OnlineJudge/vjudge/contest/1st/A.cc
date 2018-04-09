#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const* argv[])
{
    int n;
    string re;
    int l=0,r=10000001;
    while (cin >> n && n) {
        cin >> re >> re;
        if(re=="high"){
            if(r>n)r=n;
        }
        else if(re=="low"){
            if(l<n)l=n;
        }
        else if(re=="on"){
            if(n<r && n>l)cout << "The guy may be honest" << endl;
            else cout << "The guy is dishonest" << endl;
            l=0,r=10000001;
            continue;
        }
    }
    return 0;
}

//https://vjudge.net/contest/206616#problem/A
//小学生的游戏
//用l和r分别记录左右边界，当结果在边界之内时，输出诚实，否则反之
//字符串的输入可以算是一个新发现的技巧吧。
