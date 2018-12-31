//Code By HeRaNO
#include <cstdio>
#include <cstring>
using namespace std;

int cnt_cun, cnt_scl;
int jv[505];
int dp[505][505];

int myabs(int a)
{
	return a > 0 ? a : -a;
}

int main()
{
	scanf("%d %d", &cnt_cun, &cnt_scl);
	for (int x = 2; x <= cnt_cun; x++)
	{
		int a;
		scanf("%d", &a);
		jv[x] = jv[x - 1] + a;
	}
	memset(dp, 0x7f, sizeof(dp));
	dp[0][0] = 0;
	for (int x = 1; x <= cnt_scl; x++) dp[1][x] = 0;
	int now_size = 0, next_size = 1;
	for (int x = 2; x <= cnt_cun; x++)
	{
		now_size = (1 + x) / 2;
		dp[x][1] = dp[x - 1][1] + jv[x] - jv[now_size];
		next_size = now_size;
	}
	for (int x = 2; x <= cnt_cun; x++)
	{
		for (int y = 2; y <= cnt_scl; y++)
		{
			if (y >= x)
			{
				dp[x][y] = 0;
				break;
			}
			int fewr = dp[x - 1][y - 1], next_sze = x, next_jv = 0;
			for (int z = x - 1; z >= 1; z--)
			{
				int now_sze = (1 + x + z) / 2;
				int now_jv = next_jv + myabs(jv[z] - jv[now_sze]);
				next_sze = now_sze;
				next_jv = now_jv;
				if (now_jv + dp[z - 1][y - 1] < fewr)fewr = now_jv + dp[z - 1][y - 1];
			}
			dp[x][y] = fewr;
		}
	}
	printf("%d\n", dp[cnt_cun][cnt_scl]);
	return 0;
}
