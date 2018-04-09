#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#define maxn 26
using namespace std;

char str[maxn+5];
int cnt[maxn+5];

struct Node
{
    char name;
    int num;
    bool operator <(const Node a)const
    {
        if(num!=a.num) return num>a.num;
        return name<a.name;
    }
};
Node node[maxn+5];

int main()
{
    freopen("I_in.txt","r",stdin);
    freopen("I_out.txt","w",stdout);
    //int start,finish;
    //start=clock();
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        memset(cnt,0,sizeof(cnt));

        while(1)
        {
            gets(str);
            for(int i=0;i<strlen(str);i++)
            {
                if(str[i]=='#') cnt[i]++;
            }
            if(str[0]=='A') break;
        }

        for(int i=0;i<strlen(str);i++)
        {
            node[i].name='A'+i;
            node[i].num=cnt[i];
        }
        sort(node,node+strlen(str));

        printf("Case #%d:\n",kase);
        printf("%d\n",strlen(str));
        for(int i=0;i<strlen(str);i++)
        {
            printf("%c %d\n",node[i].name,node[i].num);
        }
    }
    //finish=clock();
    //printf("%d\n",finish-start);
    return 0;
}
