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
const int N = 1000050;
const int inf = 0x3f3f3f3f;
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
inline ll mi(ll a, ll b, ll MOD)
{
	ll ret = 1;
	a %= MOD;
	while (b)
	{
		if (b & 1)
			ret *= a, ret %= MOD;
		a *= a, a %= MOD;
		b >>= 1;
	}
	return MOD;
}
ll m;
ll x1, y1, h1, a1, x2, y2, a2, h2;
bool vis[N];
inline ll cal(ll h, ll a, ll x, ll y)
{
	memarray(vis, 0);
	int ret = 0;
	while (true)
	{
		if (vis[h])
			return -1;
		vis[h] = 1;
		h = h * x + y;
		h %= m;
		ret++;
		if (h == a)
			return ret;
	}
}

void solve()
{
	cin >> m;
	cin >> h1 >> a1 >> x1 >> y1;
	cin >> h2 >> a2 >> x2 >> y2;
	ll p1 = cal(h1, a1, x1, y1);
	ll p2 = cal(a1, a1, x1, y1);
	if (p1 == -1)
		return puts("-1"), void();
	ll q1 = cal(h2, a2, x2, y2);
	ll q2 = cal(a2, a2, x2, y2);
	if (q1 == -1)
		return puts("-1"), void();
	if (p1 == q1)
		return printf("%lld\n", p1), void();
	if (p2 == -1 && q2 == -1)
		return puts("-1"), void();
	if (p2 == -1 || q2 == -1)
	{
		if (q2 == -1)
			swap(p2, q2), swap(p1, q1);
		if (p1 >= q1 && (p1 - q1) % q2 == 0)
			return printf("%lld\n", p1), void();
		else
			return puts("-1"), void();
	}
	for (ll i = 0; i <= m; ++i)
	{
		if (p1 + p2 * i >= q1 && (p1 + p2 * i - q1) % q2 == 0)
		{
			printf("%lld\n", p1 + p2 * i);
			return;
		}
	}
	puts("-1");
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