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
const int N = 20;
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
int n, m;
int a[N][N];
ll dp[N][st(N)], ans;
int linest[N][N];
int nowline[N][st(N)];
bool validy[N];
int isValidy(int S, int j)
{
	int lst1 = -1, lst2 = -1;
	bool up = false;
	for (int i = 0; i < n; ++i)
	{
		if (S & st(i))
		{
			if (lst1 == -1)
				lst1 = a[i][j];
			else if (lst2 == -1)
				lst2 = a[i][j];
			else
			{
				if (lst1 < lst2)
					up = true;
				if (up && lst2 > a[i][j])
					validy[j] = 0;
				else if (up == false && lst2 < a[i][j])
					validy[j] = 0;
				lst2 = a[i][j];
				if (validy[j] == false)
					return 0;
			}
		}
	}
	return validy[j];
}
ll dp_process(int S, int j)
{
	ll ret = 0;
	if (!validy[j])
		return 0;
	for (int k = j + 1; k < m; ++k)
	{
		if (!validy[k])
			continue;
		int nowst = (S & linest[j][k]);
		if (nowline[j][nowst] != S)
			nowline[j][nowst] = S, dp[j][nowst] = 0;
		if (nowline[k][nowst] != S)
			nowline[k][nowst] = S, dp[k][nowst] = 0;
		dp[k][nowst] += dp[j][nowst] + 1;
		ret += dp[j][nowst] + 1;
	}
	return ret;
}

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);
	for (int j = 0; j < m; ++j)
		for (int k = j + 1; k < m; ++k)
			for (int i = 0; i < n; ++i)
				linest[j][k] |= ((a[i][j] < a[i][k]) ? st(i) : 0);
	for (int S = 1; S < st(n); ++S)
	{
		for (int j = 0; j < m; ++j)
			validy[j] = 1;
		for (int j = 0; j < m; ++j)
			ans += isValidy(S, j);
		for (int j = 0; j < m; ++j)
			ans += dp_process(S, j);
	}
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