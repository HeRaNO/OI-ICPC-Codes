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
const int N = 5000050;
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
int ans;
int n, m, allst;
int a[N];
bool is[N];
bool vis[N];
void dfs(int x)
{
	if (vis[x])
		return;
	vis[x] = 1;
	if (is[x])
		dfs(allst ^ x);
	for (int i = 0; i <= n; ++i)
	{
		if (st(i) & x)
			dfs(x ^ st(i));
	}
}

void solve()
{
	cin >> n >> m;
	allst = st(n) - 1;
	for (int i = 1; i <= m; ++i)
		scanf("%d", &a[i]), is[a[i]] = 1;
	for (int i = 1; i <= m; ++i)
	{
		if (!vis[a[i]])
		{
			ans++;
			vis[a[i]] = 1;
			dfs(a[i] ^ allst);
		}
	}
	printf("%d\n", ans);
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