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
#define vecsort(v) (sort(v.begin(), v.end()))
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353LL;
const ll bound=1e18;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
int r, m, s, d, n;
ll ans;
ll b[1005];
set<int> a[105];
bool cant[105][105];
set<int> S;
inline bool iscan(int i, int j, int k)
{
	return (!cant[i][j]) && (!cant[i][k]) && (!cant[j][k]);
}
inline bool isbaocheng(ll t, ll x)
{
	if (t > bound / x)
		return false;
	return true;
}
inline bool isbaojia(ll t, ll x)
{
	if (t > 1e18 - x)
		return false;
	return true;
}

void solve()
{
	scanf("%d%d%d%d%d", &r, &s, &m, &d, &n);
	for (int i = 1; i <= r; ++i)
		scanf("%lld", &b[i]);
	for (int i = 1; i <= s + m + d; ++i)
	{
		int num;
		scanf("%d", &num);
		while (num--)
		{
			int x;
			scanf("%d", &x);
			a[i].insert(x);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		cant[x][y] = cant[y][x] = 1;
	}
	for (int i = 1; i <= s; ++i)
		for (int j = s + 1; j <= s + m; ++j)
			for (int k = s + m + 1; k <= s + m + d; ++k)
			{
				if (!iscan(i, j, k))
					continue;
				S.clear();
				for (auto x : a[i])
					S.insert(x);
				for (auto x : a[j])
					S.insert(x);
				for (auto x : a[k])
					S.insert(x);
				ll tmp = 1;
				for (auto u : S)
				{
					if (!isbaocheng(tmp, b[u]))
						return puts("too many"), void();
					tmp *= b[u];
				}
				if (!isbaojia(ans, tmp))
					return puts("too many"), void();
				ans += tmp;
			}
	printf("%lld\n", ans);
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