#include <cstdio>
#define ZERO 1000
#define MAXN 1010
#define MOD 9901
using namespace std;

int n, a[MAXN], dp[MAXN][2010], ans;

inline void read(int &x)
{
	x = 0;
	bool f = false;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x = f ? -x : x;
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 2; i <= n; i++)
		for (int j = 1; j < i; j++)
			(dp[i][a[i] - a[j] + ZERO] += dp[j][a[i] - a[j] + ZERO] + 1) %= MOD;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= (ZERO << 1); j++)
			(ans += dp[i][j]) %= MOD;
	printf("%d\n", ans + n);
	return 0;
}