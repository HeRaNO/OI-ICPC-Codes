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
int n;
char A[N], B[N];
int dp[1050][1050];
int Right;

void solve()
{
	scanf("%s", A + 1);
	scanf("%s", B + 1);
	n = strlen(A + 1);
	for (int i = 0; i <= min(n, 1000); ++i)
	{
		for (int j = 0; j <= min(n, 1000); ++j)
		{
			while (dp[i][j] + 1 + i <= n && dp[i][j] + 1 + j <= n && A[dp[i][j] + 1 + i] == B[dp[i][j] + 1 + j])
				dp[i][j]++;
			Right = max(Right, dp[i][j]);
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
		}
	}
	if (Right * 100 >= n * 99)
		puts("Long lost brothers D:");
	else
		puts("Not brothers :(");
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