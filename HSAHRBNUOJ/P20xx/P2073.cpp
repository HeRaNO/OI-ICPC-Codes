#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	std::vector<int> a(n);
	for (int &i : a) scanf("%d", &i);
	std::vector<std::pair<int, std::pair<int, int>>> edges;
	for (int i = 1; i <= m; i++)
	{
		int u, v; scanf("%d %d", &u, &v); --u; --v;
		edges.push_back({std::lcm(a[u], a[v]), {u, v}});
	}
	std::sort(edges.begin(), edges.end());
	std::vector<int> f(n);
	std::iota(f.begin(), f.end(), 0);
	std::vector<std::vector<int>> g(n);
	int edge_cnt = 0;
	for (auto [w, edge] : edges)
	{
		int u, v; std::tie(u, v) = edge;
		std::function<int(int)> getf = [&](int x)
		{
			return x == f[x] ? x : f[x] = getf(f[x]);
		};
		int fu = getf(u), fv = getf(v);
		if (fu != fv)
		{
			f[fv] = fu; ++edge_cnt;
			g[u].push_back(v); g[v].push_back(u);
			if (edge_cnt == n - 1)
				break;
		}
	}
	std::function<void(int, int)> dfs = [&](int x, int fa)
	{
		f[x] = fa;
		for (int v : g[x])
			if (v != fa) dfs(v, x);
		return ;
	};
	dfs(0, -1);
	int ans = 0;
	for (int x = n - 1; x; x = f[x])
		ans = std::max(ans, std::lcm(a[x], a[f[x]]));
	printf("%d\n", ans);
	return 0;
}