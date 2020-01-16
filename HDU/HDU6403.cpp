#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

const long long M=998244353;

struct link
{
	int to,val,nxt;
};

link e[MAXN];
int head[MAXN],ecnt;
int T,n,x,y,V,E,ans,cnt,f[MAXN],dp[MAXN],p[MAXN];
bool vis[MAXN];
pair <int,int> cir;
int ecir;

inline void add(int u,int v)
{
	e[++ecnt]=(link){v,1,head[u]};head[u]=ecnt;
	e[++ecnt]=(link){u,0,head[v]};head[v]=ecnt;
}

void dfs(int x)
{
	if (vis[x]) return ;
	vis[x]=true;V+=2;
	for (int i=head[x];~i;i=e[i].nxt) ++E,dfs(e[i].to);
	return ;
}

void findCirAndDP(int x,int fa)
{
	vis[x]=true;f[x]=0;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=fa)
		{
			if (!vis[e[i].to])
			{
				findCirAndDP(e[i].to,x);
				f[x]+=f[e[i].to]+e[i].val;
			}
			else
			{
				cir={x,e[i].to};ecir=i;
			}
		}
	return ;
}

void DP(int x,int fa)
{
	p[++p[0]]=dp[x];
	for (int i=head[x];~i;i=e[i].nxt)
		if (i!=ecir&&(i^1)!=ecir&&e[i].to!=fa)
		{
			dp[e[i].to]=dp[x]+(e[i].val?-1:1);
			DP(e[i].to,x);
		}
	return ;
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
	read(T);
	while (T--)
	{
		memset(vis,false,sizeof vis);ans=0;cnt=1;
		read(n);memset(head,-1,sizeof head);ecnt=1;bool fl=true;
		for (int i=1;i<=n;i++) read(x),read(y),add(x,y);
		for (int i=1,p=n<<1;i<=p&&fl;i++)
		{
			V=0;E=0;dfs(i);
			if (E>V) fl=false;
		}
		if (!fl){puts("-1 -1");continue;}
		memset(vis,false,sizeof vis);
		for (int i=1,q=n<<1;i<=q;i++)
			if (!vis[i])
			{
				ecir=-1;findCirAndDP(i,-1);
				dp[i]=f[i];p[0]=0;DP(i,-1);
				if (!~ecir)
				{
					int mn=~(1<<31),c=0;
					for (int j=1;j<=p[0];j++) mn=min(mn,p[j]);
					for (int j=1;j<=p[0];j++) c+=(p[j]==mn);
					ans+=mn;cnt=1LL*cnt*c%M;
				}
				else
				{
					ecir&=1;
					if (dp[cir.first]+ecir==dp[cir.second]+(ecir^1)) cnt<<=1;
					if (cnt>=M) cnt-=M;
					ans+=min(dp[cir.first]+ecir,dp[cir.second]+(ecir^1));
				}
			}
		printf("%d %d\n",ans,cnt);
	}
	return 0;
}