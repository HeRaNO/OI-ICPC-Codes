#include <cstdio>
#include <vector>
#include <functional>

int main()
{
	int n;
	scanf("%d", &n);
	std::vector<std::vector<int>> g(n);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a,&b); --a; --b;
		g[a].push_back(b); g[b].push_back(a);
	}
	std::vector<int> siz(n, 0), dep(n, 0);
	std::function<void(int, int, int)> dfs1 = [&](int x, int fa, int deep) {
		dep[x] = deep; siz[x] = 1;
		for (int v : g[x])
			if (v != fa)
			{
				dfs1(v, x, deep + 1);
				siz[x] += siz[v];
			}
		return ;
	};
	dfs1(0, -1, 0);
	long long sdep = 0;
	for (int i : dep) sdep += i;
	long long ans = 0;
	std::vector<long long> f(n, 0);
	std::function<void(int, int, int, long long)> dfs2 = [&](int x, int fa, int deep, long long now) {
		if (deep)
			f[deep] = f[deep - 1] + siz[fa] - siz[x];
		if (deep > 1)
			now = now - (f[deep] - f[deep / 2 + 1]) + siz[x];
		ans = std::max(ans, now);
		for (int v : g[x])
			if (v != fa) dfs2(v, x, deep + 1, now);
		return ;
	};
	dfs2(0, -1, 0, 0);
	printf("%lld\n", sdep - ans);
	return 0;
}