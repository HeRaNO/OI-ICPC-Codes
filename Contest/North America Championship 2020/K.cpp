#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define fillarray(array, value, begin, end) fill((array) + (begin), (array) + (end) + 1, value)
#define fillvector(v, value) fill((v).begin(), (v).end(), value)
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
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
	printf("\n\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
int n, q;
const int MAXN = N, MAXM = N;
struct Edge
{
	int v, nxt;
} e[MAXM];

int head[MAXN], ecnt;

void add_edge(int u, int v)
{
	e[++ecnt] = {v, head[u]};
	head[u] = ecnt;
}

int dep[MAXN], fa[MAXN][20], dfn[MAXN], dfncnt, m;

void LCA_pre_dfs(int u, int f, int d)
{
	dep[u] = d;
	fa[u][0] = f;
	dfn[u] = ++dfncnt;
	for (int i = head[u]; i; i = e[i].nxt)
	{
		if (e[i].v != f)
			LCA_pre_dfs(e[i].v, u, d + 1);
	}
}

void LCA_pre()
{
	LCA_pre_dfs(1, 0, 1);
	for (int j = 1; j <= 19; j++)
		for (int i = 1; i <= n; i++)
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
}

int LCA(int u, int v)
{
	if (dep[u] < dep[v])
		swap(u, v);
	int delta = dep[u] - dep[v];
	for (int i = 19; i >= 0; i--)
		if ((delta >> i) & 1)
			u = fa[u][i];
	for (int i = 19; i >= 0; i--)
		if (fa[u][i] ^ fa[v][i])
		{
			u = fa[u][i];
			v = fa[v][i];
		}
	if (u == v)
		return u;
	return fa[u][0];
}
inline int getdis(int x, int y)
{
	return dep[x] + dep[y] - (2 * dep[LCA(x, y)]) + 1;
}

inline void solve()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add_edge(x, y);
		add_edge(y, x);
	}
	LCA_pre();
	while(q--)
	{
		int p, r;
		scanf("%d%d", &p, &r);
		ll dis = getdis(p, r);
		ll ans = (n - dis) + (dis + 1) * dis / 2;
		printf("%lld\n", ans);
	}
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	// scanf("%d", &Test);
	while (Test--)
	{
		solve();
		// if (Test)
		//     putchar('\n');
	}
	TIME__END = clock();
	program_end();
	return 0;
}
