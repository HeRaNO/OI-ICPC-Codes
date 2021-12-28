#include <bits/stdc++.h>
#define MAXN 100010
#define MAXM 100010
using namespace std;

namespace Tarjan_SCC
{
	struct link
	{
		int to,val,nxt;
	};

	link e[MAXM];
	int head[MAXN],cnt;
	int n,m,T,u,v,w,scc,top;
	int dfn[MAXN],low[MAXN],bel[MAXN],sta[MAXN];
	bool vis[MAXN];

	inline void add(int u,int v,int w) // One way
	{
		e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
	}

	inline void Tarjan(int x,int fa)
	{
		dfn[x]=low[x]=++T;sta[++top]=x;
		for (int i=head[x];~i;i=e[i].nxt)
		{
			if (vis[e[i].to]||e[i].to==fa) continue;
			if (dfn[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
			else
			{
				Tarjan(e[i].to,x);
				low[x]=min(low[x],low[e[i].to]);
			}
		}
		if (dfn[x]==low[x])
		{
			int t;scc++;
			do{
				vis[t=sta[top--]]=true;
				bel[t]=scc;
			} while (t!=x);
		}
		return ;
	}
}

namespace Tarjan_EBCC // Must 1-based
{
	vector <pair<int,int> > g[MAXN];
	int n,m,T,u,v,w,bcc,top;
	int dfn[MAXN],low[MAXN],vbel[MAXN],ebel[MAXM],sta[MAXN+MAXM];
	bool vis[MAXM];

	inline void add(int u,int v,int i) // Two way
	{
		g[u].push_back({v,i});
		g[v].push_back({u,i});
	}

	inline void Tarjan(int x,int fa)
	{
		dfn[x]=low[x]=++T;sta[++top]=x;
		for (auto i:g[x])
		{
			int v=i.first,pt=i.second;
			if (vis[pt]) continue;
			vis[pt]=true;sta[++top]=-pt;
			if (dfn[v]) low[x]=min(low[x],dfn[v]);
			else
			{
				Tarjan(v,pt);
				low[x]=min(low[x],low[v]);
			}
		}
		if (dfn[x]==low[x])
		{
			for (++bcc;sta[top]!=-fa;--top)
				sta[top]>0?vbel[sta[top]]=bcc:ebel[-sta[top]]=bcc;
			if (top) --top;
		}
		return ;
	}
}

namespace Tarjan_VBCC_BCTree
{
	struct link
	{
		int to,nxt;
	};

	link e[MAXN<<1];
	int head[MAXN],cnt,bel[MAXN];
	int n,m,Q,T,R,u,v,bcc,low[MAXN],dfn[MAXN],sta[MAXN],top;
	vector <int> s[MAXN],g[MAXN<<1];
	bool cut[MAXN];

	inline void add(int u,int v)
	{
		e[cnt]=(link){v,head[u]};head[u]=cnt++;
		e[cnt]=(link){u,head[v]};head[v]=cnt++;
	}

	inline void addg(int u,int v)
	{
		g[u].push_back(v);g[v].push_back(u);
		return ;
	}

	inline void Tarjan(int x,int fa)
	{
		dfn[x]=low[x]=++T;sta[++top]=x;
		for (int i=head[x];~i;i=e[i].nxt)
		{
			if (!dfn[e[i].to])
			{
				Tarjan(e[i].to,x);
				low[x]=min(low[x],low[e[i].to]);
				if (low[e[i].to]>=dfn[x])
				{
					cut[x]|=(dfn[x]>1||dfn[e[i].to]>2);
					++bcc;int y;
					do{
						y=sta[top--];s[bcc].push_back(y);
					}while (y!=e[i].to);
					s[bcc].push_back(x);
				}
			}
			else
				low[x]=min(low[x],dfn[e[i].to]);
		}
		return ;
	}

	inline void BuildTree()
	{
		int cnt=0;
		for (int i=1;i<=n;i++) if (cut[i]) bel[i]=++cnt;
		for (int i=1;i<=bcc;i++)
		{
			++cnt;
			for (auto x:s[i])
			{
				if (cut[x]) addg(bel[x],cnt);
				else bel[x]=cnt;
			}
		}
		return ;
	}
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
	using namespace Tarjan_SCC;
	// using namespace Tarjan_EBCC;
	// using namespace Tarjan_VBCC_BCTree;
	memset(head,-1,sizeof head);
	// Make Graph
	for (int i=1;i<=n;i++) if (!dfn[i]) Tarjan(i,0);
	return 0;
}
