#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
#define vecfirst (*vec.begin())
#define veclast (*vec.rbegin())
#define vecall(v) (v).begin(), (v).end()
#define vecupsort(v) (sort((v).begin(), (v).end()))
#define vecdownsort(v, type) (sort(vecall(v), greater<type>()))
#define veccmpsort(v, cmp) (sort(vecall(v), cmp))
using namespace std;
const int N = 50050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
const int M = 201;
int s[N][M], a[N];
int n;
int b[N], d[N], f[N][16], son[N], dep[N], top[N], g[N];
vector<int> e[N], u[N], v[N];
void dfs(int x, int fa)
{
	dep[x] = d[x] = d[fa] + 1;
	f[x][0] = fa;
	for (int i = 1; (1 << i) <= d[x]; i++)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for (auto y : e[x])
	{
		if (y == fa)
			continue;
		dfs(y, x);
		if (dep[y] > dep[x])
			dep[x] = dep[y], son[x] = y;
	}
}
inline int getlca(int a, int b)
{
	if (d[a] > d[b])
		swap(a, b);
	for (int i = 15; i >= 0; i--)
		if (d[a] <= d[b] - (1 << i))
			b = f[b][i];
	if (a == b)
		return a;
	for (int i = 15; i >= 0; i--)
	{
		if (f[a][i] == f[b][i])
			continue;
		else
			a = f[a][i], b = f[b][i];
	}
	return f[a][0];
}
inline int getdis(int x, int y) { return d[x] + d[y] - 2 * d[getlca(x, y)]; }
void dfs(int x, int p, int fa)
{
	top[x] = p;
	if (x == p)
	{
		for (int i = 0, o = x; i <= dep[x] - d[x]; ++i)
			u[x].pb(o), o = f[o][0];
		for (int i = 0, o = x; i <= dep[x] - d[x]; ++i)
			v[x].pb(o), o = son[o];
	}
	if (son[x])
		dfs(son[x], p, f[son[x]][0]);
	for (auto y : e[x])
		if (y != son[x] && y != fa)
			dfs(y, y, x);
}
inline int ask(int x, int k)
{
	if (!k)
		return x;
	x = f[x][g[k]], k -= 1 << g[k], k -= d[x] - d[top[x]], x = top[x];
	return k >= 0 ? (k < (int)u[x].size() ? u[x][k] : -1) : (k < (int)v[x].size() ? v[x][-k] : -1);
}
void dfs2(int x, int fa)
{
	for (int j = 1; j < M; ++j)
	{
		if (ask(x, j) == -1)
			s[x][j] = a[x];
		else
			s[x][j] = s[ask(x, j)][j] + a[x];
	}
	for (auto vv : e[x])
	{
		if (vv == fa)
			continue;
		dfs2(vv, x);
	}
}

inline int queryBig(int x, int y, int k)
{
	int resx = 0, resy = 0;
	int lca = getlca(x, y), D = getdis(x, y);
	int dx = getdis(x, lca), dy = getdis(y, lca);
	if (lca == x)
	{
		int ry = D % k;
		if (ry)
			resy += a[y];
		y = ask(y, ry);
		while (~y && d[y] >= d[lca])
			resy += a[y], y = ask(y, k);
		return resy;
	}
	while (~x && d[x] > d[lca])
		resx += a[x], x = ask(x, k);
	if (lca == y)
		return resx + a[y];
	int ry = D % k;
	if (ry)
		resy += a[y];
	y = ask(y, ry);
	while (~y && d[y] > d[lca])
		resy += a[y], y = ask(y, k);
	if (dx % k == 0 || dy % k == 0)
		resx += a[lca];
	return resx + resy;
}
inline int querySmall(int x, int y, int k)
{
	int resx = 0, resy = 0;
	int lca = getlca(x, y), D = getdis(x, y);
	int ry = D % k;
	if (ry)
		resy += a[y];
	if (lca == x)
	{
		y = ask(y, ry);
		int lcay = ask(lca, k);
		resy += (y == -1 ? 0 : s[y][k]) - (lcay == -1 ? 0 : s[lcay][k]);
		return resy;
	}
	if (lca == y)
	{
		int lcax = ask(lca, k - D % k);
		resx += s[x][k] - (lcax == -1 ? 0 : s[lcax][k]);
		return resx;
	}
	int dx = getdis(x, lca);
	int lcax = ask(lca, k - dx % k);
	resx += s[x][k] - (lcax == -1 ? 0 : s[lcax][k]);
	y = ask(y, ry);
	int lcay = ask(lca, dx % k);
	resy += (y == -1 ? 0 : s[y][k]) - (lcay == -1 ? 0 : s[lcay][k]);
	return resx + resy;
}

inline void solve()
{
	scanf("%d", &n);
	g[0] = -1;
	for (int i = 1; i <= n; ++i)
		g[i] = g[i >> 1] + 1, scanf("%d", &a[i]);
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y), e[y].push_back(x);
	}
	dfs(1, 0);
	dfs(1, 1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	int uu, vv, k;
	for (int i = 2; i <= n; ++i)
	{
		scanf("%d", &k);
		int ans = 0;
		if (k >= M)
			ans = queryBig(b[i - 1], b[i], k);
		else
			ans = querySmall(b[i - 1], b[i], k);
		printf("%d\n", ans);
	}
}

int main()
{
	// freopen("D:\\Codes\\#vs-codes\\cpp\\2020summer\\Div.1#24\\11.in", "r", stdin);
	// freopen("H.out", "w", stdout);
	TIME__START = clock();
	int Test = 1;
	// scanf("%d", &Test);
	while (Test--)
		solve();
	TIME__END = clock();
	program_end();
	return 0;
}
/*
8
1 1 1 1 1 1 1 1
1 2
2 3
3 4
4 5
5 6
6 7
7 8
1 4 7 2 5 8 3 6
3 3 3 3 3 3 3
*/