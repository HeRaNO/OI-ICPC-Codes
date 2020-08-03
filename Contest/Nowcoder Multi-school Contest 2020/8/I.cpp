#include <bits/stdc++.h>
#define MAXN 300005
#define MAXM 500005
using namespace std;

int n, m, ans, S, T, a[MAXN], b[MAXN];
queue <int> q;
vector <pair<int,int*> > v;

vector<int> g[MAXN]; int n1, n2;
int lnk[MAXN], dis[MAXN], dm; bool vis[MAXN];

void clr_hk(int n, int m) {
	n1 = n; n2 = m;
	for (int i = 1; i <= n1 + n2; ++i)
		g[i].clear();
}

bool bfs_hk() {
	queue<int> q; dm = INT_MAX;
	fill(dis + 1, dis + n1 + n2 + 1, -1);
	for (int i = 1; i <= n1; ++i)
		if (!lnk[i]) q.push(i), dis[i] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (dis[u] > dm) break;
		for (int v : g[u]) {
			if (dis[v] != -1) continue;
			dis[v] = dis[u] + 1;
			if (!lnk[v]) dm = dis[v];
			else dis[lnk[v]] = dis[v] + 1, q.push(lnk[v]);
		}
	}
	return dm != INT_MAX;
}

int dfs_hk(int u) {
	for (int v : g[u]) {
		if (vis[v] || dis[v] != dis[u] + 1) continue;
		vis[v] = 1;
		if (lnk[v] && dis[v] == dm) continue;
		if (lnk[v] && !dfs_hk(lnk[v])) continue;
		lnk[v] = u; lnk[u] = v; return 1;
	}
	return 0;
}

int hk() {
	fill (lnk + 1, lnk + n1 + n2 + 1, 0);
	int res = 0;
	while (bfs_hk()) {
		fill (vis + 1, vis + n1 + n2 + 1, 0);
		for (int i = 1; i <= n1; ++i)
			if (!lnk[i] && dfs_hk(i)) res++;
	}
	return res;
}

inline void add(int u,int v)
{
	g[u].push_back(v+n);
}

int main()
{
	int C;
	scanf("%d",&C);
	for (int cas=1;cas<=C;cas++)
	{
		m=0;
		scanf("%d",&n);v.clear();v.push_back({-1,NULL});
		for (int i=1;i<=n;i++)
		{
			scanf("%d %d",&a[i],&b[i]);
			v.push_back({a[i],&a[i]});
			v.push_back({b[i],&b[i]});
		}
		sort(v.begin(),v.end());
		for (int i=1;i<v.size();i++)
		{
			if (v[i].first!=v[i-1].first) ++m;
			*v[i].second=m;
		}
		clr_hk(n,m);
		for (int i=1;i<=n;i++) add(i,a[i]),add(i,b[i]);
		printf("Case #%d: %d\n",cas,hk());
	}
	return 0;
}