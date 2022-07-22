#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	std::vector<std::vector<std::pair<int, int>>> g(n + 1);
	for (int i = 1, x; i <= n; i++)
	{
		scanf("%d", &x);
		g[i - 1].push_back({i, x});
	}
	for (int i = 0; i < n; i++) g[i + 1].push_back({i, 0});
	for (int i = 1; i <= m; i++)
	{
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);
		g[r].push_back({l - 1, -x});
	}
	std::queue<int> q;
	std::vector<bool> vis(n + 1, false);
	std::vector<long long> dis(n + 1, 1LL << 60);
	dis[n] = 0; vis[n] = false; q.push(n);
	while (!q.empty())
	{
		int x = q.front(); q.pop(); vis[x] = false;
		for (auto [v, w] : g[x])
			if (dis[v] > dis[x] + w)
			{
				dis[v] = dis[x] + w;
				if (!vis[v])
				{
					vis[v] = true;
					q.push(v);
				}
			}
	}
	printf("%lld\n", -dis[0]);
	return 0;
}