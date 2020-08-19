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
const int N = 3000050;
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
ll a, b, c, d, x, y, n = 3000000, ans = 1;
int vis[N], pri[N], tot;
inline ll mi(ll a, ll b)
{
	ll ret = 1;
	a %= mod;
	while (b)
	{
		if (b & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}
void shaipri(int n)
{
	for (int i = 2; i <= n; ++i)
	{
		if (!vis[i])
			vis[i] = i, pri[++tot] = i;
		for (int j = 1; j <= tot && i * pri[j] <= n; ++j)
		{
			vis[i * pri[j]] = pri[j];
			if (i % pri[j] == 0)
				break;
		}
	}
}
int vx[N], vy[N];
vector<int> prix, priy;
ll cntp[N];

inline ll f(ll upx, ll upy)
{
	if (upx < 1 || upy < 1)
		return 1;
	ll ret = 1;
	for (auto nowpri : prix)
	{
		cntp[nowpri] = 0;
		if (vy[nowpri] == 0)
			continue;
		ll dx = vx[nowpri], dy = vy[nowpri];
		for (int i = 1; i <= upx; ++i)
		{
			ll cntx = 1ll * i * dx;
			ll s = min(cntx / dy, upy);
			cntp[nowpri] += s * (s + 1) / 2 * dy + cntx * (upy - s);
			cntp[nowpri] %= (mod - 1);
			// assert(cntp[nowpri] <= 9e18);
		}
		// assert(cntp[nowpri] <= 1e18);
		(ret *= mi(nowpri, cntp[nowpri])) %= mod;
	}
	return ret;
}

inline void solve()
{
	shaipri(3000000);
	scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &x, &y);
	int _x = x, _y = y;
	for (ll i = 2; i * i <= x; ++i)
	{
		int cnt = 0;
		while (_x % i == 0)
			_x /= i, cnt++;
		if(cnt)
			vx[i] = cnt, prix.push_back(i);
	}
	if(_x)
		vx[_x] = 1, prix.push_back(_x);
	for (ll i = 2; i * i <= y; ++i)
	{
		int cnt = 0;
		while (_y % i == 0)
			_y /= i, cnt++;
		if(cnt)
			vy[i] = cnt;
	}
	if(_y)
		vy[_y] = 1;
	ans = f(b, d) * mi(f(a - 1, d), mod - 2) % mod * mi(f(b, c - 1), mod - 2) % mod * f(a - 1, c - 1) % mod;
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
/*
3000000
3000000 3000000 3000000 536870912 536870912
*/