//#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class inf{
public:
    string name;
    string plac;
    int num;
    bool operator<(const inf L)const{
        if(L.plac!=plac)return L.plac>plac;
        else return L.name>name;
    }
    friend istream & operator>>(istream & is,inf & R){
        is >> R.name >> R.plac >> R.num;
        return is;
    }
};
int main(int argc, char const* argv[])
{
    int t;cin >> t;
    while (t--) {
        int n;cin >> n;
        inf *data=new inf[n];
        for(int i=0;i<n;i++)
            cin >> data[i];
        sort(data,data+n);

        string s1=data[0].plac,s2;
        map<string,int>mmp;
        map<string,int>::iterator it;
        for(int i=0;i<n;i++){
            if(data[i].plac==s1){
                mmp[data[i].name]+=data[i].num;
            }
            else{
                cout << s1 << endl;
                for(it=mmp.begin();it!=mmp.end();it++){
                    cout << "   |----" << it->first 
                         << '(' << it->second << ')' << endl;
                }
                mmp.clear();
                s1=data[i].plac;
                mmp[data[i].name]+=data[i].num;
            }
        }

        cout << s1 << endl;
        for(it=mmp.begin();it!=mmp.end();it++){
            cout << "   |----" << it->first 
                 << '(' << it->second << ')' << endl;
        }
        if(t)cout << endl;
        delete [] data;
    }
    return 0;
}


//https://vjudge.net/contest/205706#problem/C
//
//水题系列，结构题排序加map的简单使用
//
//注意，每两组数据用空行隔开，最后一组没有多余空行(PE两次，分别犯了...)
