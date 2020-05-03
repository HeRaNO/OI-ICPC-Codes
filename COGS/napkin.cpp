#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 2010
#define MAXM 200100
using namespace std;

struct edge
{
    int from;
    int to;
    int nxt;
    int flow;
    int cost;
};

edge e[MAXM];
int p[MAXN],dis[MAXN];
bool vis[MAXN];
int n,new_cost,fast_day,fast_cost;
int slow_day,slow_cost;
int edge_num[MAXN],cnt=1;
int S,T,x,ans;
queue <int> q;

inline void add(int u,int v,int flow,int val)
{
    cnt++;e[cnt]=(edge){u,v,edge_num[u],flow,val}; edge_num[u]=cnt;
    cnt++;e[cnt]=(edge){v,u,edge_num[v],0,-val}; edge_num[v]=cnt;
}

int mymin(int a,int b)
{
    return a<b?a:b;
}

bool spfa()
{
    for (int i=S;i<=T;i++) dis[i]=INT_MAX;
    memset(vis,false,sizeof(vis));
    q.push(S);dis[S]=0;vis[S]=true;
    while (!q.empty())
    {
        int u=q.front();q.pop();vis[u]=false;
        for (int i=edge_num[u];i;i=e[i].nxt)
        {
            if (e[i].flow&&dis[e[i].to]>dis[u]+e[i].cost)
            {
                dis[e[i].to]=dis[u]+e[i].cost;
                p[e[i].to]=i;
                if (!vis[e[i].to])
                {
                    vis[e[i].to]=true;
                    q.push(e[i].to);
                }
            }
        }
    }
    if (dis[T]==INT_MAX) return false;
    else return true;
}

void Min_Cost_Max_Flow()
{
    int i,x=INT_MAX;
    i=p[T];
    while (i)
    {
        x=mymin(e[i].flow,x);
        i=p[e[i].from];
    }
    i=p[T];
    while (i)
    {
        e[i].flow-=x;
        e[i^1].flow+=x;
        ans+=x*e[i].cost;
        i=p[e[i].from];
    }
    return ;
}

int main()
{
    freopen("napkin.in","r",stdin);freopen("napkin.out","w",stdout);
    //memset(edge_num,-1,sizeof(edge_num));
    scanf("%d",&n);
    S=0;T=2*n+1;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        add(S,i,x,0);
        add(i+n,T,x,0);
    }
    scanf("%d %d %d %d %d",&new_cost,&fast_day,&fast_cost,&slow_day,&slow_cost);
    for (int i=1;i<=n;i++)
    {
        if (i+1<=n) add(i,i+1,INT_MAX,0);
        if (i+fast_day<=n) add(i,i+n+fast_day,INT_MAX,fast_cost);
        if (i+slow_day<=n) add(i,i+n+slow_day,INT_MAX,slow_cost);
        add(S,i+n,INT_MAX,new_cost);
    }
    while (spfa()) Min_Cost_Max_Flow();
    printf("%d\n",ans);
    return 0;
}
