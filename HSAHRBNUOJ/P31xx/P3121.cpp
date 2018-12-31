#include <cstdio>
#define MAXN 1010
#define MOD 100003
using namespace std;
int c[MAXN][MAXN];
int n, k;
int main()
{
	for (int i = 1; i < MAXN; i++)
	{
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
	}
	scanf("%d %d", &n, &k);
	printf("%d\n", c[n][k]);
	return 0;
}
