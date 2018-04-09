#include <bits/stdc++.h>
using namespace std;

map<string,string> mmp;

int main()
{
    mmp.clear();
    string strL,strR;
    while (1) {
        cin >> strL;
        if(strL=="START")continue;
        if(strL=="END")break;
        cin >> strR;
        mmp[strR]=strL;
    }
    char aim[3010];
    cin >> strR;
    getchar();//吃换行符。
    while (1) {
        cin.getline(aim,3009);
        if(strcmp(aim,"END")==0)break;
        strL="";
        for(int i=0;i<(int)strlen(aim);i++){
            if(islower(aim[i])){
                strL+=aim[i];
            }
            else{
                if(mmp[strL]!=""){
                    cout << mmp[strL];
                }
                else {
                    cout << strL;
                    //cout << aim[i];
                }
                strL="";
                cout << aim[i];
            }
        }
        cout << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205706#problem/B
//
//换行符是世界上最恶心的东西。。。
//对于所由在map里面的东西，输出翻译，否则输出原字符串
//对于其他符号不进行处理
//
//花说我为什么作死地用c风格字符串。。。。。。
