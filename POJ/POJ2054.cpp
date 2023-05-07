#include <set>
#include <cstdio>

const int N = 1005;

int c[N], siz[N], F[N], fa[N];

struct Cmp
{
	bool operator () (const int &x, const int &y) const {
		return c[x] * siz[y] == c[y] * siz[x] ? x < y : c[x] * siz[y] > c[y] * siz[x];
	}
};

std::set<int, Cmp> S;

int getf(int x)
{
	return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

void Solve(int n, int r)
{
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]), siz[i] = 1;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		F[v] = u;
	}
	for (int i = 1; i <= n; i++) fa[i] = i, S.insert(i);
	int ans = 0; siz[0] = 1; c[0] = 0; F[r] = 0;
	while (!S.empty())
	{
		int x = *S.begin(); S.erase(S.begin());
		int f = fa[x] = getf(F[x]);
		if (f) S.erase(f);
		ans += c[x] * siz[f]; siz[f] += siz[x]; c[f] += c[x];
		if (f) S.insert(f);
	}
	printf("%d\n", ans);
	return ;
}

int main()
{
	int n, r;
	while (scanf("%d %d", &n, &r) == 2)
	{
		if (!n && !r) break;
		Solve(n, r);
	}
	return 0;
}