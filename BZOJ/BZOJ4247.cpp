#include <cstdio>
#include <cstring>
#define MAXN 2010
#define ZERO 2000
using namespace std;

int n, ans;
int V[MAXN], C[MAXN];
int dp[MAXN][MAXN << 1];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	read(n);
	for (int i = 0; i < n; i++) read(V[i]), read(C[i]);
	memset(dp, -0x3f, sizeof dp);
	dp[0][ZERO + 1] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= ZERO << 1; j++)
		{
			if (j + V[i] - 1 < 0) continue;
			dp[i + 1][mymin(j + V[i] - 1, ZERO << 1)] = mymax(dp[i + 1][mymin(j + V[i] - 1, ZERO << 1)], dp[i][j] + C[i]);
			dp[i + 1][j] = mymax(dp[i + 1][j], dp[i][j]);
		}
	for (int i = ZERO; i <= ZERO << 1; i++) ans = mymax(ans, dp[n][i]);
	printf("%d\n", ans);
	return 0;
}
