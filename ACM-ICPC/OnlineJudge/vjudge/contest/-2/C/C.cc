#include<cstdio>
#include<cmath>
using namespace std;

const double eps=1e-8;

struct Point
{
    double x,y;
    Point(){}
    Point(double a,double b):x(a),y(b){}
    friend Point operator +(const Point &a,const Point &b)
    {
        return Point(a.x+b.x,a.y+b.y);
    }
    friend Point operator -(const Point &a,const Point &b)
    {
        return Point(a.x-b.x,a.y-b.y);
    }
    friend Point operator *(const double &k,const Point &p)
    {
        return Point(k*p.x,k*p.y);
    }
    friend bool operator ==(const Point &a,const Point &b)
    {
        return fabs(a.x-b.x)<eps && fabs(a.y-b.y)<eps;
    }
    friend Point operator /(const Point a,double k)
    {
        return Point(a.x/k,a.y/k);
    }
};
typedef Point Vector;
double cross(Vector a,Vector b)
{
    return a.x*b.y-a.y*b.x;
}

struct Line
{
    Point p;
    Vector v;
    Line(){}
    Line(Point a,Vector b):p(a),v(b){}
};
bool parallel(Line a,Line b)
{
    if(fabs(a.v.x*b.v.y-a.v.y*b.v.x)<eps)
        return true;
    return false;
}
bool line_make_point(Line a,Line b,Point &res)
{
    if(parallel(a,b)) return false;
    Vector u=a.p-b.p;
    double t=cross(b.v,u)/cross(a.v,b.v);
    res=a.p+t*a.v;
    return true;
}

Point p[5],res;

Point geto(Point a,Point b,Point c)
{
    Point res;
    Vector v1=Vector(-b.y+a.y,b.x-a.x);
    Vector v2=Vector(-c.y+b.y,c.x-b.x);
    //printf("v1=%lf %lf\nv2=%lf %lf\n",v1.x,v1.y,v2.x,v2.y);
    Line l1=Line((a+b)/2,v1);
    Line l2=Line((b+c)/2,v2);
    if(!line_make_point(l1,l2,res))
    {
        return Point(-1001,-1001);
    }
    else
    {
        return res;
    }
}

double getdist(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

void solve()
{
    Point o=geto(p[0],p[1],p[2]);
    //printf("o=%lf %lf\n",o.x,o.y);
    if(o.x==-1001)
    {
        printf("No\n");
    }
    double r=getdist(o,p[0]);
    for(int i=3;i<5;i++)
    {
        if(fabs(getdist(o,p[i])-r)>eps)
        {
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
}

int main()
{
    freopen("C_in.txt","r",stdin);
    freopen("C_out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        for(int i=0;i<5;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        printf("Case #%d: ",kase);
        solve();
    }
    return 0;
}
