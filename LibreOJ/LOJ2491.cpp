#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 300010
using namespace std;

const long long M=998244353LL;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,T,a,b,m,x;
long long p[MAXN][51],s[MAXN][51],ans,pm;
int f[MAXN][20],_2pow[20],d[MAXN],k;

inline void add(int a,int b)
{
	e[cnt]=(link){b,head[a]};head[a]=cnt++;
	e[cnt]=(link){a,head[b]};head[b]=cnt++;
}

void dfs(int x,int fa)
{
	f[x][0]=fa;d[x]=d[fa]+1;
	for (int i=head[x];~i;i=e[i].nxt) if (e[i].to!=fa) dfs(e[i].to,x);
	return ;
}

inline void LCA()
{
	for (int j=1;j<=k;j++)
		for (int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
	return ;
}

inline int lca(int x,int y)
{
	if (d[x]>d[y]) swap(x,y);
	for (int i=k;~i;i--) if (_2pow[i]<=d[y]-d[x]) y=f[y][i];
	if (x==y) return x;
	for (int i=k;~i;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	memset(head,-1,sizeof head);
	read(n);for (_2pow[0]=1;_2pow[k]<=n;k++) _2pow[k+1]=_2pow[k]<<1;
	for (int i=1;i<=n;i++) p[i][0]=1;
	for (int j=1;j<=50;j++)
		for (int i=1;i<=n;i++)
		{
			p[i][j]=(1LL*p[i][j-1]*i)%M;
			s[i][j]=(s[i-1][j]+p[i][j])%M;
		}
	for (int i=1;i<n;i++) read(a),read(b),add(a,b);d[0]=-1;
	dfs(1,0);LCA();
	read(T);d[0]=0;
	while (T--)
	{
		read(a);read(b);read(m);
		x=lca(a,b);
		ans=s[d[a]][m]+s[d[b]][m];ans%=M;
		pm=(s[d[x]][m]+s[d[f[x][0]]][m])%M;
		printf("%lld\n",(ans-pm+M)%M);
	}
	return 0;
}