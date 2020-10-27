#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+5;
typedef double db;
typedef long long ll;

int head[MAXN],_next[MAXN],to[MAXN],val[MAXN],ecnt;
void add_Edge(int u,int v,int w)
{
    _next[++ecnt]=head[u];
    to[ecnt]=v;
    val[ecnt]=w;
    head[u]=ecnt;
}

ll dep[MAXN],col[MAXN][5];
db ans=0;
int m[4];

void dfssz(int u,int f)
{
    for(int j=1;j<=3;j++)
    ans+=(db)dep[u]*col[u][j]/m[j];
    for(int i=head[u];i;i=_next[i])if(to[i]!=f)
    {
        dep[to[i]]=dep[u]+val[i];
        dfssz(to[i],u);
        for(int j=1;j<=3;j++)
            col[u][j]+=col[to[i]][j];
    }
}

void dfs(int u,int f)
{
    for(int i=head[u];i;i=_next[i])if(to[i]!=f)
    {
        for(int j=1;j<=3;j++)
            for(int k=j+1;k<=3;k++)if(j!=k)
            {
                ans-=(db)col[to[i]][j]*col[to[i]][k]*val[i]/m[j]/m[k];
            }
        dfs(to[i],u);
    }
}

void solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_Edge(u,v,w);
        add_Edge(v,u,w);
    }
    for(int i=1;i<=3;i++)
    {
        scanf("%d",&m[i]);
        for(int j=1;j<=m[i];j++)
        {
            int p;scanf("%d",&p);
            col[p][i]=1;
        }
    }
    dfssz(1,0);
    dfs(1,0);
    printf("%.12lf",ans);
}

int main()
{
    int T=1;
    //scanf("%d",&T);
    while(T--)
    {
        solve();
    }
}
