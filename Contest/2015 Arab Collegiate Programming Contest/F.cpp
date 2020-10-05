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
int n, m;
const int MAXN = 500050, MAXM = 500050;
struct tarjan_one_direction
{
	int head[MAXN], _next[MAXM], to[MAXM], ecnt;
	int nodenum[MAXN];
	void add_Edge(int u, int v)
	{
		_next[++ecnt] = head[u];
		to[ecnt] = v;
		head[u] = ecnt;
		_next[++ecnt] = head[v];
		to[ecnt] = u;
		head[v] = ecnt;
	}
	int tot, dfn[MAXN], low[MAXN];
	int cir[MAXN], cirnum;
	stack<int> s;
	void init(int n, int m)
	{
		ecnt = 0;
		mem(head, 0, n, int);
		mem(_next, 0, m * 2, int);
		mem(to, 0, m * 2, int);
		tot = 0;
		while (!s.empty())
			s.pop();
		cirnum = 0;
		mem(dfn, 0, n, int);
		mem(low, 0, n, int);
		mem(cir, 0, n, int);
		mem(nodenum, 0, n, int);
	}
	void tarjan(int u, int f)
	{
		dfn[u] = low[u] = ++tot;
		s.push(u);
		for (int i = head[u]; i; i = _next[i])
		{
			int v = to[i];
			if (f == v)
				continue;
			if (!dfn[v])
			{
				tarjan(v, u);
				low[u] = min(low[u], low[v]);
			}
			else if (!cir[v])
				low[u] = min(low[u], dfn[v]);
		}
		if (dfn[u] == low[u])
		{
			cir[u] = ++cirnum;
			nodenum[cirnum]++;
			while (s.top() != u)
			{
				cir[s.top()] = cirnum;
				nodenum[cirnum]++;
				s.pop();
			}
			s.pop();
		}
	}
	void solve()
	{
		for (int i = 1; i <= n; i++)
			if (!dfn[i])
				tarjan(i, 0);
	}
} tarjan;
vector<int> e[MAXN];
int col[MAXN], sz[MAXN];
bool vis[MAXN];
ll ans;
ll f[MAXN], dep[MAXN];
int nowsz;
vector<int> vec;
ll dfs(int u, int fa)
{
	nowsz++;
	sz[u] = 1;
	for (auto v : e[u])
	{
		if (v == fa)
			continue;
		dep[v] = dep[u] + 1;
		sz[u] += dfs(v, u);
	}
	return sz[u];
}
void dfs1(int n, int u, int fa)
{
	for (auto v : e[u])
	{
		if (v == fa)
			continue;
		f[v] = f[u];
		ll tmp = n - sz[v] - 1;
		f[v] += tmp - (sz[v] - 1);
		dfs1(n, v, u);
	}
}
void dfs3(int u, int fa)
{
	vis[u] = 1;
	vec.push_back(u);
	for (int i = tarjan.head[u]; i; i = tarjan._next[i])
	{
		int v = tarjan.to[i];
		if (v == fa)
			continue;
		if (col[u] != col[v])
		{
			e[u].push_back(v), e[v].push_back(u);
			dfs3(v, u);
		}
	}
}

inline void solve()
{
	ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; ++i)
		e[i].resize(0);
	mem(col, 0, n, int);
	mem(vis, 0, n, bool);
	tarjan.init(n, m);
	for (int i = 1; i <= m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		tarjan.add_Edge(x, y);
	}
	tarjan.solve();
	for (int i = 1; i <= n; ++i)
		col[i] = tarjan.cir[i];
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i])
		{
			vec.resize(0);
			dfs3(i, 0);
			dfs(i, 0);
			vecupsort(vec);
			vec.resize(unique(vecall(vec)) - vec.begin());
			ll sum = 0;
			for (auto u : vec)
				sum += dep[u];
			f[i] = sum;
			dfs1(nowsz, i, 0);
			for (auto u : vec)
				ans += f[u];
			for (auto u : vec)
				f[u] = 0, dep[u] = 0, sz[u] = 0, e[u].resize(0);
			nowsz = 0;
		}
	}
	// for (int i = 1; i <= n; ++i)
	// {
	//     if (col[tarjan.cir[i]] || vis[tarjan.cir[i]])
	//         continue;
	//     vec.resize(0);
	//     dfs(tarjan.cir[i], 0);
	//     vecupsort(vec);
	//     vec.resize(unique(vecall(vec)) - vec.begin());
	//     ll sum = 0;
	//     for (auto u : vec)
	//         sum += dep[u];
	//     f[tarjan.cir[i]] = sum;
	//     dfs1(nowsz, tarjan.cir[i], 0);
	//     for (auto u : vec)
	//         ans += f[u];
	//     for (auto u : vec)
	//         f[u] = 0, dep[u] = 0, sz[u] = 0;
	//     nowsz = 0;
	// }
	// for (int i = 1; i <= tarjan.cirnum; ++i)
	// {
	//     if (!col[i])
	//         continue;
	//     for (auto v : e[i])
	//     {
	//         if (col[v])
	//             ans++;
	//     }
	// }
	printf("%lld\n", ans / 2);
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	scanf("%d", &Test);
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