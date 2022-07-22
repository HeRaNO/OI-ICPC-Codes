// Author: HeRaNO
#include <tuple>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

struct UnionSet
{
	std::vector<int> f;
	UnionSet(){}
	UnionSet(int n)
	{
		f.reserve(n);
		for (int i = 0; i < n; i++)
			f.emplace_back(i);
	}
	int getf(int x){ return x == f[x] ? x : f[x] = getf(f[x]); }
	void Union(int u, int v)
	{
		u = getf(u); v = getf(v);
		if (u != v) f[v] = u;
	}
	bool SameSet(int u, int v)
	{
		u = getf(u); v = getf(v);
		return u == v;
	}
};

inline void Solve()
{
	int n, m;
	scanf("%d %d", &n, &m);
	std::vector<std::pair<int, int>> e;
	e.reserve(m);
	std::vector<int> v;
	v.reserve(m);
	for (int i = 0; i < m; i++)
	{
		int x, y, p;
		scanf("%d %d %d", &x, &y, &p);
		--x; --y;
		e.emplace_back(x, y);
		v.emplace_back(p);
	}
	for (int bit = 29; ~bit; --bit)
	{
		std::vector<std::vector<int>> g(n);
		std::vector<int> color(n, 0);
		UnionSet S(n);
		bool failed = false;
		for (int i = 0; i < m; i++)
			if (!(v[i] >> bit & 1))
			{
				int x, y; std::tie(x, y) = e[i];
				S.Union(x, y);
			}
		for (int i = 0; i < m; i++)
			if (v[i] >> bit & 1)
			{
				int x, y; std::tie(x, y) = e[i];
				if (S.SameSet(x, y))
					return puts("No"), void();
				x = S.getf(x); y = S.getf(y);
				g[x].push_back(y); g[y].push_back(x);
			}
		std::function<void(int, int)> dfs = [&](int u, int c)
		{
			color[u] = c;
			for (int v: g[u])
			{
				if (color[v] == c)
				{
					failed = true;
					break;
				}
				else if (!color[v])
					dfs(v, 3 ^ c);
			}
			return ;
		};

		for (int i = 0; i < n; i++)
			if (!color[i])
			{
				dfs(i, 1);
				if (failed)
					return puts("No"), void();
			}
	}
	return puts("Yes"), void();
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) Solve();
	return 0;
}