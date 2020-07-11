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
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f;
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
int f[N];
int Find(int x) { return x == f[x] ? x : f[x] = Find(f[x]); }
int n, m, k, w;
int specialpoint[N];
struct edges
{
	int u, v;
	ll cost;
	int special;
} e[N];
bool cmp(const edges &x, const edges &y)
{
	return x.cost < y.cost || (x.cost == y.cost && x.special > y.special);
}
ll ans = -1;

int check(ll x)
{
	int ret = 0;
	ll allcost = 0;
	for (int i = 1; i <= n; ++i)
		f[i] = i;
	for (int i = 1; i <= m; ++i)
	{
		if (e[i].special)
			e[i].cost += x;
	}
	sort(e + 1, e + m + 1, cmp);
	int cnt = 0;
	for (int i = 1; i <= m; ++i)
	{
		int fx = Find(e[i].u), fy = Find(e[i].v);
		if (fx == fy)
			continue;
		cnt++;
		f[fy] = fx;
		if (e[i].special)
			ret++;
		allcost += e[i].cost;
		if (cnt == n - 1)
			break;
	}
	for (int i = 1; i <= m; ++i)
	{
		if (e[i].special)
			e[i].cost -= x;
	}
	if (cnt != n - 1)
		return -1;
	if (ret >= w)
	{
		ans = allcost - x * w;
		return ret;
	}
	return 0;
}

void solve()
{
	cin >> n >> m >> k >> w;
	for (int i = 1; i <= k; ++i)
	{
		int x;
		scanf("%d", &x);
		specialpoint[x] = 1;
	}
	int specialcnt = 0;
	for (int i = 1; i <= m; ++i)
	{
		int x, y;
		ll cost;
		scanf("%d%d%lld", &x, &y, &cost);
		e[i].u = x, e[i].v = y, e[i].cost = cost;
		if ((specialpoint[x] + specialpoint[y]) == 1)
			e[i].special = true, specialcnt++;
	}
	if (specialcnt < w)
		return puts("-1"), void();
	ll L = -inf, R = inf, res;
	while (L <= R)
	{
		ll mid = (L + R) >> 1;
		if (check(mid) == -1)
			return puts("-1"), void();
		else if (check(mid) >= w)
			L = mid + 1, res = mid;
		else
			R = mid - 1;
	}
	if (check(res) == -1)
		ans = -1;
	cout << ans << '\n';
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	// cin >> Test;
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}