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
const int N = 500050;
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
int n;
ll L[N], R[N];
ll h[N];
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &h[i]);
	for (int i = 1; i <= n;++i)
		L[i] = min(L[i - 1] + 1, h[i]);
	for (int i = n; i >= 1;--i)
		R[i] = min(R[i + 1] + 1, h[i]);
	ll ans = 0;
	for (int i = 1; i <= n;++i)
		ans = max(ans, min(L[i], R[i]));
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