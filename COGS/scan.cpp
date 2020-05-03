#include <cstdio>
#define MAXN 55
using namespace std;

int a[MAXN][MAXN][MAXN];
int l,w,h,m,ans;
bool vis[MAXN][MAXN][MAXN];

inline int myabs(int a){return a>0?a:-a;}

inline void read(int &x)
{
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    x*=f;return ;
}

void dfs(int x,int y,int z)
{
    vis[x][y][z]=true;
    if (x>=2&&myabs(a[x-1][y][z]-a[x][y][z])<=m&&!vis[x-1][y][z]) dfs(x-1,y,z);
    if (x+1<=l&&myabs(a[x+1][y][z]-a[x][y][z])<=m&&!vis[x+1][y][z]) dfs(x+1,y,z);
    if (y>=2&&myabs(a[x][y-1][z]-a[x][y][z])<=m&&!vis[x][y-1][z]) dfs(x,y-1,z);
    if (y+1<=w&&myabs(a[x][y+1][z]-a[x][y][z])<=m&&!vis[x][y+1][z]) dfs(x,y+1,z);
    if (z>=2&&myabs(a[x][y][z-1]-a[x][y][z])<=m&&!vis[x][y][z-1]) dfs(x,y,z-1);
    if (z+1<=h&&myabs(a[x][y][z+1]-a[x][y][z])<=m&&!vis[x][y][z+1]) dfs(x,y,z+1);
    return ;
}

int main()
{
    freopen("scan.in","r",stdin);freopen("scan.out","w",stdout);
    read(l);read(w);read(h);read(m);
    for (int i=1;i<=l;i++)
        for (int j=1;j<=w;j++)
            for (int k=1;k<=h;k++)
                read(a[i][j][k]);
    for (int i=1;i<=l;i++)
        for (int j=1;j<=w;j++)
            for (int k=1;k<=h;k++)
                if (!vis[i][j][k])
                {
                    ans++;
                    vis[i][j][k]=true;
                    dfs(i,j,k);
                }
    printf("%d\n",ans);
    return 0;
}
