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
};

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	UnionSet S(n + m);
	for (int i = 1; i <= k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		S.Union(x - 1, y - 1 + n);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (S.getf(i) == i) ++ans;
	printf("%d\n", ans - (k || n == 1));
	return 0;
}