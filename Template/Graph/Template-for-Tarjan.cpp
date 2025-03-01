#include <bits/stdc++.h>
#define MAXN 100010
#define MAXM 100010
using namespace std;

namespace Tarjan_SCC
{
	vector<int> g[MAXN];
	int n,m,T,scc,top;
	int dfn[MAXN],low[MAXN],bel[MAXN],sta[MAXN];
	bool vis[MAXN];

	void Tarjan(int x)
	{
		dfn[x]=low[x]=++T;sta[++top]=x;vis[x]=true;
		for (int v:g[x])
		{
			if (!dfn[v]) 
			{
				Tarjan(v);
				low[x]=min(low[x],low[v]);
			}
			else if (vis[v])
				low[x]=min(low[x],dfn[v]);
		}
		if (dfn[x]==low[x])
		{
			int t;scc++;
			do {
				vis[t=sta[top--]]=false;
				bel[t]=scc;
			} while (t!=x);
		}
		return ;
	}
}

namespace Tarjan_EBCC
{
	vector<pair<int, int>> g[MAXN];
	int T, bcc;
	int dfn[MAXN], low[MAXN];
	bool is_brige[MAXM];
	vector<vector<int>> ans;
	stack<int> stk;

	void add(int u,int v,int i) // Two way
	{
		g[u].push_back({v,i});
		g[v].push_back({u,i});
	}

	void Tarjan(int x,int fa)
	{
		dfn[x] = low[x] = ++T; stk.push(x);
		for (auto [v, pt] : g[x])
		{
			if (!dfn[v])
			{
				tarjan(v, pt);
				low[x] = std::min(low[x], low[v]);
			}
			else if (pt != f)
				low[x] = std::min(low[x], dfn[v]);
		}
		if (dfn[x] == low[x])
		{
			if (f != -1) is_brige[f] = true;
			++bcc; std::vector<int> vec;
			for (; stk.top() != x; stk.pop())
				vec.push_back(stk.top());
			vec.push_back(x); stk.pop();
			ans.emplace_back(vec);
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
