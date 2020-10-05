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
int n, k;
int a[55][55];
bool vis[55 * 55];
int dp[55 * 55];
int ans;
inline int id(int i, int j) { return (i - 1) * n + j; }
vector<pii> vec[55 * 55];

inline void solve()
{
	scanf("%d%d", &n, &k);
	memarray(dp, inf);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			vis[a[i][j]] = 1;
	for (int i = 1; i <= k; ++i)
		if (!vis[i])
			return puts("-1"), void();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			vec[a[i][j]].push_back(mp(i, j));
	for (auto i : vec[1])
		dp[id(i.first, i.second)] = 0;
	for (int i = 2; i <= k; ++i)
	{
		for (auto j : vec[i])
			for (auto k : vec[i - 1])
			{
				int idj = id(j.first, j.second);
				int idk = id(k.first, k.second);
				dp[idj] = min(dp[idj], dp[idk] + abs(j.first - k.first) + abs(j.second - k.second));
			}
	}
	int ans = inf;
	for(auto i : vec[k])
	{
		ans = min(ans, dp[id(i.first, i.second)]);
	}
	cout << ans << '\n';
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