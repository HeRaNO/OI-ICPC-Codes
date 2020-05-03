#include <cstdio>
#include <cstring>
#define MAXN 210
using namespace std;

struct link
{
    int to;
    int nxt;
};

link e[MAXN*MAXN];
int edge_num[MAXN],cnt;
int n,x;
int a[MAXN],val[MAXN],g[MAXN][MAXN];
bool vis[MAXN],cir[MAXN];
int ans,rt[MAXN];

inline void add(int u,int v)
{
    e[cnt]=(link){v,edge_num[u]};edge_num[u]=cnt++;
}

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

bool dfs(int x)
{
    cir[x]=vis[x]=true;
    for (int i=edge_num[x];~i;i=e[i].nxt)
    {
        if (cir[e[i].to]) return false;
        if (!vis[e[i].to]) if (!dfs(e[i].to))return false;
        if (val[x]<val[e[i].to])
        {
            val[x]=val[e[i].to];
            memset(g[x],0,sizeof g[x]);
            g[x][++g[x][0]]=e[i].to;
        }
        else if (val[x]==val[e[i].to]) g[x][++g[x][0]]=e[i].to;
    }
    val[x]+=a[x];
    cir[x]=false;
    return true;
}

void collectans(int x)
{
    vis[x]=true;
    for (int i=1;i<=g[x][0];i++) collectans(g[x][i]);
}

int main()
{
    freopen("project.in","r",stdin);freopen("project.out","w",stdout);
    memset(edge_num,-1,sizeof edge_num);
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
        {
			if(i==j) continue;
			x=read();if(x) add(i,j);
		}
    for (int i=1;i<=n;i++)
        if (!vis[i])
            if (!dfs(i))
            {
                puts("-1");return 0;
            }
    for (int i=1;i<=n;i++)
    {
        if (ans<val[i])
        {
            ans=val[i];
            rt[0]=0;
            rt[++rt[0]]=i;
        }
        else if (ans==val[i]) rt[++rt[0]]=i;
    }
    printf("%d\n",ans);
    memset(vis,false,sizeof vis);
    for (int i=1;i<=rt[0];i++) collectans(rt[i]);
    for (int i=1;i<=n;i++) if (vis[i]) printf("%d ",i);
    puts("");
    return 0;
}
