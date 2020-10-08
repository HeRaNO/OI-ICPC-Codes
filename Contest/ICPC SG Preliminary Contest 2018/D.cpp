#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#define MAXN 10005
#define MAXM 100005
using namespace std;

int ans;

namespace Tarjan_EBCC
{
	vector <int> g[MAXN];
	int n,m,T,u,v,w;
	int dfn[MAXN], low[MAXN], bel[MAXN], dfc, bcc;
	int bcs[MAXN], *bct = bcs;

	inline void add(int u,int v) // Two way
	{
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int dfs_bcc(int u, int f) {
		*bct++ = u; dfn[u] = low[u] = ++dfc;
		for (int v : g[u]) {
			if (v == f) continue;
			if (!dfn[v]) low[u] = min(low[u], dfs_bcc(v, u));
			else low[u] = min(low[u], low[v]);
		}
		if (dfn[u] == low[u])
			for (++bcc; *bct != u; --bct)
				bel[bct[-1]] = bcc;
		return low[u];
	}
}

int main()
{
	using namespace Tarjan_EBCC;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		add(u+1,v+1);
	}
	dfs_bcc(1,0);
	for (int i=1;i<=n;i++) ans+=(bel[i]==bel[1]);
	printf("%d\n",ans);
	return 0;
}