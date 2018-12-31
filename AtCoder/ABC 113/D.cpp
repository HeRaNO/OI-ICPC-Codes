#include <cstdio>
#define MAXH 105
#define MAXW 10
using namespace std;

const long long M = 1000000007LL;

int h, w, k;
bool f;
long long dp[MAXH][MAXW];

int main()
{
	scanf("%d %d %d", &h, &w, &k);
	dp[1][1] = 1LL;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			for (int p = 0, q = 1 << (w - 1); p < q; p++)
			{
				f = false;
				for (int r = 1; r < w && !f; r++) if ((p & (1 << r)) && (p & (1 << (r - 1)))) f = true;
				if (f) continue;
				if (j >= 2 && ((p >> (j - 2)) & 1))(dp[i + 1][j - 1] += dp[i][j]) %= M;
				else if (j <= w - 1 && ((p >> (j - 1)) & 1))(dp[i + 1][j + 1] += dp[i][j]) %= M;
				else (dp[i + 1][j] += dp[i][j]) %= M;
			}
	printf("%lld\n", dp[h + 1][k]);
	return 0;
}