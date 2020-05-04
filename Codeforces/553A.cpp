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
const int N = 1050;
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
ll k;
ll c[N];
ll fac[N], inv[N];
inline ll mi(ll a, ll b)
{
	ll ret = 1;
	while (b)
	{
		if (b & 1)
			ret *= a, ret %= mod;
		a *= a, a %= mod;
		b >>= 1;
	}
	return ret;
}
inline ll C(ll n, ll m)
{
	return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void solve()
{
	inv[0] = fac[0] = 1;
	for (int i = 1; i <= 1000; ++i)
		fac[i] = fac[i - 1] * i % mod, inv[i] = mi(fac[i], mod - 2);
	cin >> k;
	ll n = 0;
	for (int i = 1; i <= k; ++i)
	{
		cin >> c[i];
		n += c[i];
	}
	ll ans = 1;
	for (int i = k; i ; --i)
	{
		ans *= C(n - 1, c[i] - 1);
		ans %= mod;
		n -= c[i];
	}
	cout << ans << endl;
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