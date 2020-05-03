#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXM 2010
#define MAXN 110
using namespace std;

struct link
{
    int from;
    int to;
    int val;
    double var;
};

double EPS;
link e[MAXM],re[MAXM];
int n,m;
int father[MAXN];
double l,r,ans=2147483647.00;

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

bool cmp(link a,link b)
{
    return a.val<b.val;
}

bool cmp_var(link a,link b)
{
    return a.var<b.var;
}

inline double mymin(double a,double b)
{
    return a<b?a:b;
}

int getfather(int x)
{
    return x==father[x]?x:father[x]=getfather(father[x]);
}

inline int ordinary_MST()
{
    int res=0;int cnt=0;
    for (int i=1;i<=n;i++) father[i]=i;
    for (int i=1;i<=m;i++)
    {
        int fx=getfather(e[i].from);
        int fy=getfather(e[i].to);
        if (fx!=fy)
        {
            father[fx]=fy;
            res+=e[i].val;
            cnt++;
        }
        if (cnt==n-1) break;
    }
    return res;
}

inline double var_MST(double average)
{
    double res=0.0;int cnt=0;
    for (int i=1;i<=n;i++) father[i]=i;
    for (int i=1;i<=m;i++) e[i].var=(average-e[i].val)*(average-e[i].val);
    sort(e+1,e+m+1,cmp_var);
    for (int i=1;i<=m;i++)
    {
        int fx=getfather(e[i].from);
        int fy=getfather(e[i].to);
        if (fx!=fy)
        {
            father[fx]=fy;
            res+=e[i].var;
            cnt++;
        }
        if (cnt==n-1) break;
    }
    return sqrt(res/(double)(n-1));
}

int main()
{
    freopen("happy_birthday.in","r",stdin);freopen("happy_birthday.out","w",stdout);
    n=read();m=read();EPS=0.03;
    for (int i=1;i<=m;i++)
        e[i].from=read(),e[i].to=read(),e[i].val=read();
    sort(e+1,e+m+1,cmp);
    for (int i=1;i<n;i++)
    {
        l+=(double)e[i].val;
        r+=(double)e[m-i+1].val;
    }
    l=l/(double)(n-1);r=r/(double)(n-1);
    for (int i=0;EPS*i+l<=r;i++) ans=mymin(ans,var_MST(EPS*i+l));
    printf("%.4lf\n",ans);
    return 0;
}
