#include <cstdio>
#include <cstring>
#define MAXN 1010
#define MAXV 110
using namespace std;

int T, V, A, W;
int n[MAXN], b[MAXN], a[MAXN][MAXV];
int dp[MAXN][MAXV];

inline void get_method(int x, int y)
{
	if (!x) return ;
	get_method(x - 1, y + n[x] - a[x][y]);
	printf("%d\n", a[x][y]);
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	//freopen("arugal.in","r",stdin);freopen("arugal.out","w",stdout);
	memset(dp, 0x7f, sizeof dp);
	dp[0][0] = 0;
	read(T);
	read(V);
	read(A);
	read(W);
	for (int i = 1; i <= T; i++) read(n[i]), read(b[i]);
	for (int i = 1; i <= T; i++)
		for (int j = 0; j <= V; j++)
			for (int k = 0; k <= A; k++)
				if (j + n[i] >= k && j + n[i] - k <= V && dp[i][j] > dp[i - 1][j - k + n[i]] + k * b[i] + (j - k + n[i])*W)
				{
					dp[i][j] = dp[i - 1][j - k + n[i]] + k * b[i] + (j - k + n[i]) * W;
					a[i][j] = k;
				}
	printf("%d\n", dp[T][0]);
	get_method(T, 0);
	return 0;
}
