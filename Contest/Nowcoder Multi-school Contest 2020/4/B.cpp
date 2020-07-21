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
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
int n, c;
ll ans;
ll vis[1000006];
ll pri[1000005];
ll tot;
void pre()
{
	for (int i = 2; i <= 1000000; ++i)
	{
		if (!vis[i])
			vis[i] = i, pri[++tot] = i;
		for (int j = 1; j <= tot && i * pri[j] <= 1000000; ++j)
		{
			vis[i * pri[j]] = pri[j];
			if (i % pri[j] == 0)
				break;
		}
	}
}

void solve()
{
	ans = 1;
	scanf("%d%d", &n, &c);
	while (n > 1)
	{
		ll now = vis[n];
		while (n % now == 0)
		{
			n /= now;
			ans *= c;
			ans %= MOD;
		}
	}
	cout << ans << '\n';
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	pre();
	cin >> Test;
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}