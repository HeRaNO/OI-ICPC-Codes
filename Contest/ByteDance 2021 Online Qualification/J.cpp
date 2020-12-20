#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, a[N], b[N];
int f[N][2 * N * N];
int g[N][2 * N * N];
int sumb;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i], &b[i]), sumb += b[i];
	int now = 1;
	memset(f, -0x3f, sizeof f);
	memset(g, -0x3f, sizeof g);
	f[0][0] = g[0][0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i; j >= 1; --j)
		{
			for (int k = 20000; k >= 0; --k)
			{
				if (k >= 2 * a[i] - b[i])
				{
					f[j][k] = max(f[j][k], f[j - 1][k - 2 * a[i] + b[i]] + 2 * a[i]);
					g[j][k] = max(g[j][k], g[j - 1][k - 2 * a[i] + b[i]] + b[i]);
					// printf("%d %d %d %d %d\n", i, j, k, f[j][k], g[j][k]);
				}
			}
		}
		// now ^= 1;
	}
	for (int i = 1; i <= n; ++i)
	{
		int ans = 0;
		int u = n & 1;
		for (int k = 20000; k >= 0; --k)
		{
			if (k > sumb)
				ans = max(ans, sumb + g[i][k]);
			else
				ans = max(ans, f[i][k]);
		}
		printf("%.12lf ", ans / 2.0);
	}
	system("pause");
	return 0;
}