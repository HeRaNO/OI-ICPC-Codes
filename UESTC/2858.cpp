#include <cstdio>
#include <vector>

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
		return getf(u) == getf(v);
	}
};

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		int ans = n + m;
		std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		UnionSet S(n + m + 1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (a[i][j] == a[i - 1][j - 1] + 1 && a[i][j] != a[i][j - 1] && a[i][j] != a[i - 1][j])
				{
					int x = i, y = n + j;
					if (!S.SameSet(x, y))
					{
						S.Union(x, y);
						--ans;
					}
				}
		printf("%d\n", ans);
	}
	return 0;
}