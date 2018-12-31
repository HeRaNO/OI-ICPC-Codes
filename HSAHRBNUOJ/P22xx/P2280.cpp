#include <cstdio>
#define MAXN 20
using namespace std;

int A, B, n, x, y, dp[MAXN][MAXN];
bool ban[MAXN][MAXN];

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(A);
	read(B);
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(x);
		read(y);
		ban[x][y] = true;
	}
	dp[1][1] = 1;
	for (int i = 1; i <= A; i++)
		for (int j = 1; j <= B; j++)
			if (!ban[i][j])
				dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
	printf("%d\n", dp[A][B]);
	return 0;
}