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
ll likegcd(ll a, ll b, ll c, ll n)
{
	if (n == 1)
		return b / c;
	if (n <= 0)
		return 0;
	ll ans = (a / c) * ((n - 1) * n / 2);
	ans += (b / c) * n;
	a %= c;
	b %= c;
	if (a == 0)
		return ans;
	return ans + likegcd(c, (a * n + b) % c, a, (a * n + b) / c);
}

void solve()
{
	ll p, q, n;
	scanf("%lld%lld%lld", &p, &q, &n);
	ll sum = p * n * (n + 1) / 2;
	ll res = likegcd(p, p, q, n) * q;
	ll ans = sum - res;
	printf("%lld\n",ans);
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	cin >> Test;
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}