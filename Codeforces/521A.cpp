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
const ll mod = 1e9 + 7;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
char s[N];
ll cnt[26];
ll ans;

void solve()
{
	ll n;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; ++i)
		cnt[s[i] - 'A']++;
	sort(cnt, cnt + 26, greater<ll>());
	ll mx = cnt[0];
	ll m = 0;
	for (int i = 0; i < 4; ++i)
		if (cnt[i] == mx)
			m++;
	ans = 1;
	for (int i = 1; i <= n;++i)
	{
		ans *= m, ans %= mod;
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