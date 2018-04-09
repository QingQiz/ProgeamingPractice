/*jkrs*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cctype>
//#include <ext/rope>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <ctime>
#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <list>
#include <cmath>
#include <iomanip>

//#include <bits/stdc++.h>
#define pu system("pause")
#define ff first
#define ss second
#define clr(x,y) memset(x,y,sizeof (x))
#define pt(y) push_back(y)
#define mk(x,y) make_pair(x,y)
#define pof() pop_front()
#define pob() pop_back()
#define puf() push_front()
#define ls p << 1
#define rs p << 1 | 1
using namespace std;
//using namespace __gnu_cxx;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<ll,ll> Pi;

const int inf = 0x7fffffff;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const ll linf = 1e18;
const ll MAXN = 3e5 + 10;
const int MAXM = MAXN << 2;
const double E = 2.718281828;
const double pi = acos(-1.0);

struct node
{
    int fa,key,add,l,r,dis;
}heap[2][MAXN << 1];
int root,add,n;
int findn(int x)
{
    while (heap[0][x].fa)
        x = heap[0][x].fa;
    return x;
}
void down(int x)
{
    heap[0][heap[0][x].l].key += heap[0][x].add;
    heap[0][heap[0][x].r].key += heap[0][x].add;
    heap[0][heap[0][x].l].add += heap[0][x].add;
    heap[0][heap[0][x].r].add += heap[0][x].add;
    heap[0][x].add = 0;
}
int getsum(int x)
{
    int sum = 0;
    while (heap[0][x].fa)
    {
        x = heap[0][x].fa;
        sum += heap[0][x].add;
    }
    return sum;
}
void renew(int kind,int x,int val)
{
    heap[kind][x].key = val;
    heap[kind][x].fa = heap[kind][x].l = heap[kind][x].r = 0;
}
int merge(int kind,int x,int y)
{
    if (!x || !y)
        return x + y;
    if (heap[kind][x].key > heap[kind][y].key)
        swap(x,y);
    if (!kind)
        down(x);
    heap[kind][x].r = merge(kind,heap[kind][x].r,y);
    heap[kind][heap[kind][x].r].fa = x;
    int lson = heap[kind][x].l;
    int rson = heap[kind][x].r;
    if (heap[kind][lson].dis < heap[kind][rson].dis)
        swap(heap[kind][x].l,heap[kind][x].r);

    if (heap[kind][x].r)
        heap[kind][x].dis = heap[kind][heap[kind][x].r].dis + 1;
    else
        heap[kind][x].dis = 0;
    return x;
}
int pop(int kind,int x)
{
    if (!kind)
        down(x);
    int y = merge(kind,heap[kind][x].l,heap[kind][x].r);
    if (kind == 1)
    {
        if (x == root)
            root = y;
    }
    if (x == heap[kind][heap[kind][x].fa].l)
        heap[kind][heap[kind][x].fa].l = y;
    else
        heap[kind][heap[kind][x].fa].r = y;
    heap[kind][y].fa = heap[kind][x].fa;
    return findn(y);
}
int heapmodify()
{
    queue <int> q;
    while (!q.empty())
        q.pop();
    for (int i = 1;i <= n; ++ i)
        q.push(i);
    while (q.size() > 1)
    {
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();
        q.push(merge(1,x,y));
    }
    return q.front();
}
char cmd[10];
void A1()
{
    int x,v;
    scanf("%d%d",&x,&v);
    pop(1,findn(x));
    int y = pop(0,x);

    renew(0,x,heap[0][x].key + v + getsum(x));

    int z = merge(0,x,y);
    renew(1,z,heap[0][z].key);
    root = merge(1,z,root);
}
void A2()
{
    int x,v;
    scanf("%d%d",&x,&v);
    int y = findn(x);
    pop(1,y);
    heap[0][y].key += v;
    heap[0][y].add += v;
    renew(1,y,heap[0][y].key);
    root = merge(1,root,y);
}
void A3()
{
    int v;
    scanf("%d",&v);
    add += v;
}
void F1()
{
    int x;
    scanf("%d",&x);
    printf("%d\n",heap[0][x].key + add + getsum(x));
}
void F2()
{
    int x;
    scanf("%d",&x);
    printf("%d\n",heap[0][findn(x)].key + add);
}
void F3()
{
    printf("%d\n",heap[1][root].key + add);
}
void U()
{
    int x,y;
    scanf("%d%d",&x,&y);
    int f1 = findn(x);
    int f2 = findn(y);
    if (f1 != f2)
    {
        if (merge(0,f1,f2) == f1)
            pop(1,f2);
        else
            pop(1,f1);
    }

}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int m;
    int t,k = 1;
    scanf("%d",&t);
    while (t --)
    {
        scanf("%d%d",&n,&m);
        clr(heap,0);
        root = 0;
        add = 0;
        for (int i = 1;i <= n; ++ i)
            scanf("%d",&heap[0][i].key),heap[1][i].key = heap[0][i].key;
        root = heapmodify();
        printf("Case #%d:\n",k ++);
        while (m --)
        {
            scanf("%s",cmd);
            if (cmd[0] == 'a')
            {
                if (cmd[3] == '1')
                    A1();
                else if (cmd[3] == '2')
                    A2();
                else
                    A3();
            }
            else if (cmd[0] == 'f')
            {
                if (cmd[4] == '1')
                    F1();
                else if (cmd[4] == '2')
                    F2();
                else
                    F3();
            }
            else
                U();
        }
    }

    return 0;
}
