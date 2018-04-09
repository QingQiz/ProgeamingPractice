#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    string l,r;
    char q_q;
    map<string,string> T_T;
    while (1) {
        q_q=cin.peek();
        if(q_q == '\n') break;
        cin >> l >> r;
        getchar();
        T_T.insert(pair<string, string>(r, l));
    }
    string t_t;
    while (cin >> t_t){
        map<string, string>::iterator o_o = T_T.find(t_t);
        //poj auto o_o=T_T.find(t_t); 报错
        if(o_o != T_T.end())
            cout << (o_o -> second);
        else 
            cout << "eh";
        cout << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205707#problem/C
//map的水题,
//学习到的:cin.peek(),功能:从输入流中读取一个字符(返回整数),但不将其从输入流中删除
