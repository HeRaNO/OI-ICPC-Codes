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
const int N = 300050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f;
const ll mod = 998244353LL;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
int n, rt, sz[20 * N], lson[20 * N], rson[20 * N], totnode;
ll ans, a[20 * N], bin[35];
void Insert(int &x, ll v, ll d)
{
	if (!x)
		x = ++totnode;
	if (d == -1)
	{
		sz[x] = 1;
		return;
	}
	if (bin[d] & v)
		Insert(rson[x], v, d - 1);
	else
		Insert(lson[x], v, d - 1);
	sz[x] = sz[lson[x]] + sz[rson[x]];
}

ll query(int x, int v, ll d)
{
	if (d == -1)
		return 0;
	if (v & bin[d])
	{
		if (rson[x])
			return query(rson[x], v, d - 1);
		return query(lson[x], v, d - 1) + bin[d];
	}
	else
	{
		if (lson[x])
			return query(lson[x], v, d - 1);
		return query(rson[x], v, d - 1) + bin[d];
	}
}

ll Merge(int x, int y, int d, ll val, int sd)
{
	if (d == -1)
		return query(y, val, sd);
	ll ret = st(30);
	if (lson[x])
		ret = min(ret, Merge(lson[x], y, d - 1, val, sd));
	if (rson[x])
		ret = min(ret, Merge(rson[x], y, d - 1, val + bin[d], sd));
	return ret;
}

void dfs(int x, int d)
{
	if (d == -1)
		return;
	if (lson[x])
		dfs(lson[x], d - 1);
	if (rson[x])
		dfs(rson[x], d - 1);
	if (!lson[x] || !rson[x])
		return;
	int l = lson[x], r = rson[x];
	if (sz[l] > sz[r])
		swap(l, r);
	ans += Merge(l, r, d - 1, 0, d - 1) + bin[d];
}
vector<pair<int, ll>> e[100050];
void dfs2(int u, int fa)
{
	for (auto v : e[u])
	{
		if (v.first == fa)
			continue;
		a[v.first] = (a[u] ^ v.second);
		dfs2(v.first, u);
	}
}

void solve()
{
	// cout << sizeof(sz) / 1024 / 1024 << endl;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		ll cost;
		scanf("%d%d%lld", &x, &y, &cost);
		x++, y++;
		e[x].push_back({y, cost});
		e[y].push_back({x, cost});
	}
	dfs2(1, 0);
	for (int i = 1; i <= n; ++i)
	{
		Insert(rt, a[i], 30);
	}
	dfs(rt, 30);
	cout << ans << '\n';
}

int main()
{
	TIME__START = clock();
	bin[0] = 1;
	for (int i = 1; i <= 30; ++i)
		bin[i] = bin[i - 1] << 1;
	int Test = 1;
	// scanf("%d", &Test);
	while (Test--)
		solve();
	TIME__END = clock();
	program_end();
	return 0;
}
