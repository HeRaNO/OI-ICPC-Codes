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
using namespace std;
const int N = 100050;
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
ll n, m;
char s[N];
ll ans = 1;

void solve()
{
	scanf("%lld%lld", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i)
		if (s[i] != s[i - 1])
			ans += (m - 1) * n;
	ll len = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (len == 1)
		{
			if (s[i] != s[i - 1])
				len++;
		}
		else if (s[i] == s[i - 2])
			len++;
		else
		{
			ans -= len * (len - 1) / 2;
			if (s[i] == s[i - 1])
				len = 1;
			else
				len = 2;
		}
	}
	ans -= len * (len - 1) / 2;
	printf("%lld\n", ans);
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
