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
const ll mod = 100007;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
ll f[N], sum[N];
ll n;

void solve()
{
	cin >> n;
	f[0] = 1, f[1] = 3;
	sum[0] = 1, sum[1] = 4;
	for (int i = 2; i <= 10000; ++i)
	{
		f[i] = (3 * f[i - 1] - f[i - 2] + mod) % mod;
		sum[i] = sum[i - 1] + f[i], sum[i] %= mod;
	}
	// printf("%lld\n", sum[3]);
	printf("%lld\n", n * (sum[n - 2] + 1) % mod);
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