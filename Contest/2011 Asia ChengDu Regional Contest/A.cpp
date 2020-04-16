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
const int N = 50050;
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
int kase;
int dp[50100][55];
int n;
int a[55];

int dfs(int st, int one)
{
	if (one == 0)
		return st & 1;
	int &now = dp[st][one];
	if (st == 1)
		return dfs(st - 1, one + 1);
	if (~now)
		return now;
	now = 0;
	if (one > 0 && dfs(st, one - 1) == 0)
		now = 1;
	else if (one > 0 && st > 0 && dfs(st + 1, one - 1) == 0)
		now = 1;
	else if (one > 1 && dfs(st + 2 + (st ? 1 : 0), one - 2) == 0)
		now = 1;
	else if (st > 0 && dfs(st - 1, one) == 0)
		now = 1;
	return now;
}

void solve()
{
	printf("Case #%d: ", ++kase);
	scanf("%d", &n);
	int st = 0;
	int one = 0;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		one += (a[i] == 1);
	for (int i = 1; i <= n; ++i)
		if (a[i] != 1)
			st += a[i] + 1;
	if (st)
		st--;
	int ans = dfs(st, one);
	if (ans)
		puts("Alice");
	else
		puts("Bob");
}

int main()
{
	memarray(dp, -1);
	TIME_START = clock();
	int Test = 1;
	cin >> Test;
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}