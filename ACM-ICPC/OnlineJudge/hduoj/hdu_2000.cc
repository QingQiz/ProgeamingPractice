#include <bits/stdc++.h>
#define swap(a,b) ((a)=(a)^(b),(b)=(a)^(b),(a)=(a)^(b))

int main(int argc, char const* argv[])
{
    using namespace std;
    char a,b,c;
    while(std::cin >> a >> b >> c){
        a>b?swap(a,b):0;
        a>c?swap(a,c):0;
        b>c?swap(b,c):0;
        cout << a << ' ' << b << ' ' << c << endl;
    }
    return 0;
}
