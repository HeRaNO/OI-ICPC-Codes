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
int n, t, ans, mxnode, mx;
vector<int> e[N];
int father[N], dep[N];
bool cant[N];
void dfs1(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	father[u] = fa;
	for (auto v : e[u])
	{
		if (v == fa)
			continue;
		dfs1(v, u);
	}
}
void dfs2(int u, int fa, int deep)
{
	if (deep > mx)
	{
		mx = deep;
		mxnode = u;
	}
	for (auto v : e[u])
	{
		if (v == fa || cant[v])
			continue;
		dfs2(v, u, deep + 1);
	}
}

inline void solve()
{
	scanf("%d%d", &n, &t);
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y), e[y].push_back(x);
	}
	dfs1(n, 0);
	int cnt = 0, now = 1;
	while (cnt < t && now != n)
	{
		cnt++;
		now = father[now];
	}
	memarray(father, 0);
	dfs1(now, 0);
	int s = now;
	now = n;
	while (now != s)
	{
		cant[now] = 1;
		now = father[now];
	}
	mxnode = s;
	dfs2(s, 0, 0);
	memarray(father, 0);
	memarray(dep, 0);
	dfs1(mxnode, 0);
	t = n;
	while (dep[s] < dep[t])
	{
		ans++;
		if (father[s])
			s = father[s];
		if (father[t])
			t = father[t];
		if (father[t])
			t = father[t];
	}
	printf("%d\n", ans);
}

int main()
{
	TIME__START = clock();
	int Test = 1;
	// scanf("%d", &Test);
	while (Test--)
		solve();
	TIME__END = clock();
	program_end();
	return 0;
}