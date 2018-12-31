#include <cstdio>
#include <cstring>
#define MAXN 1010
#define MAXA 1024

const int compress = 1000000000;
struct big_int
{
	int len, num[50];
	big_int(): len(1)
	{
		memset(num, 0, sizeof(num));
	}
	inline void operator += (const big_int &a)
	{
		a.len > len ? len = a.len : 0;
		for (int i = 1; i <= len; i++)
		{
			num[i] += a.num[i];
			if (num[i] >= compress) num[i + 1]++, num[i] -= compress;
		}
		if (num[len + 1]) len++;
		return ;
	}
	inline void print()
	{
		printf("%d", num[len]);
		for (int i = len - 1; i; i--) printf("%09d", num[i]);
		printf("\n");
		return ;
	}
};

int n, a[MAXN];
big_int dp[2][MAXA][3];
int cur, las;

int main()
{
	scanf("%d", &n);
	for (int i = n; i; i--) scanf("%d", &a[i]);
	dp[0][1023][0].num[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		cur = las ^ 1;
		for (int j = 0; j < MAXA; j++)
			for (int k = 0; k <= 2; k++)
				dp[cur][j][k] = dp[las][j][k];
		for (int j = 0; j < MAXA; j++)
		{
			dp[cur][j & a[i]][1] += dp[las][j][0];
			dp[cur][j & a[i]][1] += dp[las][j][1];
			dp[cur][j ^ a[i]][2] += dp[las][j][1];
			dp[cur][j ^ a[i]][2] += dp[las][j][2];
		}
		las ^= 1;
	}
	dp[cur][0][2].print();
	return 0;
}
