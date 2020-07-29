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
const ll MOD = 1e9 + 7;
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
ll fac[N], inv[N];
inline ll mi(ll a, ll b)
{
	ll ret = 1;
	a %= MOD;
	while (b)
	{
		if (b & 1)
			ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}
inline ll C(ll n, ll m) { return (n < m) ? 0LL : (fac[n] * inv[m] % MOD * inv[n - m] % MOD); }
ll ans;
int f[N];
int Find(int x) { return f[x] == x ? x : f[x] = Find(f[x]); }
int one[N], two[N];

void solve()
{
	scanf("%d", &n);
	ll cntone = 0, cnttwo = 0;
	for (int i = 1; i <= n; ++i)
		f[i] = i, one[i] = two[i] = 0;
	for (int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		if (x == 1)
			one[i] = 1, cntone++;
		else
			cnttwo++, two[i] = 1;
	}
	ans = C(cnttwo, 3) + C(cnttwo, 2) * C(cntone, 1) % MOD;
	ans %= MOD;
	int m = n - 1;
	printf("%lld\n", ans);
	while (m--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		int fx = Find(u), fy = Find(v);
		if (fx == fy)
		{
			printf("%lld\n", ans);
			continue;
		}
		ans = ans - two[fx] * two[fy] % MOD * ((cntone - one[fx] - one[fy]) % MOD + MOD) % MOD;
		ans = (ans + MOD) % MOD;
		ans = ans - two[fx] * two[fy] % MOD * ((cnttwo - two[fx] - two[fy]) % MOD + MOD) % MOD;
		ans = (ans + MOD) % MOD;
		ans = ans - one[fx] * two[fy] % MOD * ((cnttwo - two[fx] - two[fy]) % MOD + MOD) % MOD;
		ans = (ans + MOD) % MOD;
		ans = ans - one[fy] * two[fx] % MOD * ((cnttwo - two[fx] - two[fy]) % MOD + MOD) % MOD;
		ans = (ans + MOD) % MOD;
		f[fy] = fx;
		one[fx] += one[fy];
		two[fx] += two[fy];
		printf("%lld\n", ans);
	}
}

int main()
{
	TIME__START = clock();
	fac[0] = 1, inv[0] = 1;
	for (int i = 1; i <= 200000; ++i)
		fac[i] = fac[i - 1] * i % MOD, inv[i] = mi(fac[i], MOD - 2);
	int Test = 1;
	scanf("%d", &Test);
	while (Test--)
		solve();
	TIME__END = clock();
	program_end();
	return 0;
}