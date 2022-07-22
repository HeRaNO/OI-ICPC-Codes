#include <cstdio>
#include <vector>
#include <functional>

int main()
{
	int n;
	scanf("%d", &n);
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	std::vector<std::vector<int>> g(n + 1);
	for (int i = 2, x; i <= n; i++)
	{
		scanf("%d", &x);
		g[x].push_back(i);
	}
	int T = 0;
	std::vector<int> in(n + 1), out(n + 1);
	std::function<void(int)> dfs = [&](int x)
	{
		in[x] = ++T;
		for (int v : g[x]) dfs(v);
		out[x] = T;
	};
	dfs(1);
	std::vector<int> c(n + 1, 0);
	std::function<void(int, int)> add = [&](int x, int v)
	{
		for (; x <= n; x += x & -x) c[x] += v;
	};
	std::function<int(int)> query = [&](int x)
	{
		int r = 0;
		for (; x; x -= x & -x) r += c[x];
		return r;
	};
	for (int i = 1; i <= n; i++) add(in[i], a[i]);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int o;
		scanf("%d", &o);
		if (o == 1)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			add(in[x], y - a[x]);
			a[x] = y;
		}
		else
		{
			int x;
			scanf("%d", &x);
			printf("%d\n", query(out[x]) - query(in[x] - 1));
		}
	}
	return 0;
}