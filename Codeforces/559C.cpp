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
const int N = 2050;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
int n;
int h, w;
ll dp[N];
ll fac[200050], inv[200050];
struct node
{
	int x, y;
	bool operator<(const node &X) const
	{
		return x + y < X.x + X.y;
	}
} e[N];
inline ll mi(ll a, ll b)
{
	ll ret = 1;
	a %= mod;
	while (b)
	{
		if (b & 1)
			ret *= a, ret %= mod;
		a *= a, a %= mod;
		b >>= 1;
	}
	return ret;
}
inline ll C(ll a, ll b)
{
	if (a < b || b < 0 || a < 0)
		return 0;
	return fac[a] * inv[b] % mod * inv[a - b] % mod;
}

void solve()
{
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= 200000; ++i)
	{
		fac[i] = fac[i - 1] * i, fac[i] %= mod;
		inv[i] = mi(fac[i], mod - 2);
	}
	scanf("%d%d%d", &h, &w, &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &e[i].x, &e[i].y);
	e[n + 1] = {1, 1}, e[n + 2] = {h, w};
	n += 2;
	sort(e + 1, e + n + 1);
	dp[1] = 1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			ll tmp = C(e[j].x + e[j].y - e[i].x - e[i].y, e[j].x - e[i].x) % mod;
			if (i > 1)
				tmp = mod - tmp;
			dp[j] = (dp[j] + tmp * dp[i] % mod) % mod;
		}
	}
	cout << dp[n] << '\n';
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