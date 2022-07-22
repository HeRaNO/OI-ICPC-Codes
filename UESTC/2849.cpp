#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	scanf("%d", &n);
	std::vector<int> l(n), r(n), s(n);
	std::vector<std::pair<int, int*>> a;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &l[i], &r[i], &s[i]);
		l[i] <<= 1;
		r[i] = r[i] << 1 | 1;
		a.push_back({l[i], &l[i]});
		a.push_back({r[i], &r[i]});
	}
	std::sort(a.begin(), a.end());
	int N = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (!i || a[i].first != a[i - 1].first) ++N;
		*a[i].second = N - 1;
	}
	std::vector<bool> vis(N, false);
	for (int i = 0; i < n; i++)
		for (int j = l[i]; j < r[i]; j++)
			vis[j] = true;
	std::vector<std::vector<std::pair<int, int>>> g(N);
	for (int i = 0; i < n; i++)
	{
		g[l[i]].push_back({r[i], s[i]});
		g[r[i]].push_back({l[i], -s[i]});
	}
	for (int i = 0; i < N - 1; i++)
	{
		g[i].push_back({i + 1, 0});
		if (!vis[i]) g[i + 1].push_back({i, 0});
	}
	std::vector<long long> dis(N, -(1LL << 60));
	dis[0] = 0;
	for (int C = 1; C <= N; C++)
		for (int i = 0; i < N; i++)
			for (auto [v, w] : g[i])
				if (dis[v] < dis[i] + w)
					dis[v] = dis[i] + w;
	bool noSol = false;
	for (int i = 0; i < N; i++)
		for (auto [v, w] : g[i])
			if (dis[v] < dis[i] + w)
				noSol = true;
	printf("%lld ", noSol ? -1 : dis[N - 1]);
	std::fill(dis.begin(), dis.end(), -(1LL << 60));
	dis[N - 1] = 0;
	for (int C = 1; C <= N; C++)
		for (int i = 0; i < N; i++)
			for (auto [v, w] : g[i])
				if (dis[v] < dis[i] + w)
					dis[v] = dis[i] + w;
	noSol = false;
	for (int i = 0; i < N; i++)
		for (auto [v, w] : g[i])
			if (dis[v] < dis[i] + w)
				noSol = true;
	printf("%lld\n", noSol ? -1 : -dis[0]);
	return 0;
}