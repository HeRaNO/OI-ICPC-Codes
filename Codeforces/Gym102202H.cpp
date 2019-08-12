#include <bits/stdc++.h>
#define MAXN 200005
#define MAXM 400005
using namespace std;

struct link
{
	int to,flow,nxt,pt;
};

link e[MAXM<<1];
int head[MAXN],cnt=1;
int n,m,u,v,S,T,st,flow,siz,dpt[MAXN],f[MAXN>>1],ans[MAXN];
int x[MAXN],y[MAXN],now[MAXN];
vector <int> g[MAXN];
bool vis[MAXN];
queue <int> q;

inline void add(int u,int v,int f,int pt)
{
	e[++cnt]=(link){v,f,head[u],pt};head[u]=cnt;
	e[++cnt]=(link){u,0,head[v],pt};head[v]=cnt;
}

inline bool BFS()
{
	memset(dpt,-1,sizeof dpt);dpt[S]=1;q.push(S);
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=head[x];~i;i=e[i].nxt)
			if (e[i].flow&&!~dpt[e[i].to])
			{
				dpt[e[i].to]=dpt[x]+1;
				q.push(e[i].to);
			}
	}
	return dpt[T]!=-1;
}

inline int Dinic(int x,int flow)
{
	int left=flow;
	if (x==T) return flow;
	for (int i=head[x];~i&&left;i=e[i].nxt)
		if (e[i].flow&&dpt[e[i].to]==dpt[x]+1)
		{
			int t=Dinic(e[i].to,min(left,e[i].flow));
			e[i].flow-=t;e[i^1].flow+=t;left-=t;
		}
	if (left) dpt[x]=-1;
	return flow-left;
}

void BuildTree(int u)
{
	for (int i=head[u];~i;i=e[i].nxt)
		if (1<=e[i].to&&e[i].to<n&&!vis[e[i].to])
		{
			g[u-n+1].push_back(f[e[i].to]-n+1);++siz;
			vis[e[i].to]=true;
			for (int j=head[e[i].to];~j;j=e[j].nxt)
			{
				if (e[j].to==f[e[i].to]) x[f[e[i].to]-n+1]=e[j].pt;
				if (e[j].to==u) y[f[e[i].to]-n+1]=e[j].pt;
			}
			BuildTree(f[e[i].to]);
		}
	return ;
}

void dfs(int u)
{
	for (int i=0;i<g[u].size();i++)
	{
		dfs(g[u][i]);
		ans[x[g[u][i]]]=n-1-now[g[u][i]];
		ans[y[g[u][i]]]=now[g[u][i]]+1;
		now[u]+=now[g[u][i]]+1;
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
	memset(head,-1,sizeof head);
	read(n);read(m);S=0;T=n<<1;
	for (int i=1;i<=m;i++)
	{
		read(u);read(v);v+=n-1;
		add(u,v,1,i);
	}
	for (int i=1;i<n;i++) add(S,i,1,i);
	for (int i=1;i<=n;i++) add(i+n-1,T,1,i);
	while (BFS()) flow+=Dinic(S,~(1<<31));
	if (flow!=n-1) return puts("-1"),0;
	for (int i=1;i<n;i++)
		for (int j=head[i];~j;j=e[j].nxt)
			if (e[j].to>=n&&e[j^1].flow)
				f[i]=e[j].to,vis[e[j].to-n+1]=true;
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			memset(vis,false,sizeof vis);
			BuildTree(i+n-1);st=i;
			break;
		}
	if (siz!=n-1) return puts("-1"),0;
	dfs(st);
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}