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
	printf("\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
int n;
ll siz[N], ans, ans2;
int f[N];
vector<int> e[N];
int dep[N];
ll dp[N];
void dfs(int u)
{
	siz[u] = 1;
	for (auto v : e[u])
	{
		dep[v] = dep[u] + 1;
		dfs(v);
		siz[u] += siz[v];
	}
	ans += siz[u];
}
void dfs2(int u)
{
	dp[u] += n - siz[u];
	ans2 = max(ans2, dp[u]);
	for (auto v : e[u])
	{
		dp[v] += dp[u];
		dfs2(v);
	}
}

inline void solve()
{
	ans = ans2 = 0;
	scanf("%d", &n);
	mem(siz, 0, n, ll);
	mem(dep, 0, n, int);
	mem(dp, 0, n, ll);
	for (int i = 1; i <= n; ++i)
		e[i].resize(0), f[i] = 0;
	for (int i = 2; i <= n; ++i)
	{
		int father;
		scanf("%d", &father);
		e[father].push_back(i);
		f[i] = father;
	}
	dfs(1);
	dfs2(1);
	printf("%lld\n", ans + ans2);
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	scanf("%d", &Test);
	while (Test--)
		solve();
	TIME__END = clock();
	program_end();
	return 0;
}
