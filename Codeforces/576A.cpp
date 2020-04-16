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
int k;
int ans[N];
int vis[N], pri[N];

void solve()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i)
	{
		if (!vis[i])
		{
			for (int j = 2 * i; j <= n; j += i)
				vis[j]++;
		}
	}
	for (int i = 2; i <= n; ++i)
		if (vis[i] <= 1)
			ans[++k] = i;
	cout << k << '\n';
	for (int i = 1; i <= k; ++i)
		cout << ans[i] << ' ';
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