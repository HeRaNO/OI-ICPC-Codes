#include <cstdio>
#include <cstring>
#define MAXN 2010
#define MOD 1000000007
using namespace std;

int n, M, L[MAXN], R[MAXN];
int dpL[MAXN][MAXN][3], dpR[MAXN][MAXN][3];
char s[MAXN];
//0:> 1:= 2:<

inline int update(long long a, long long b)
{
	a += b;
	if (a > MOD) a -= MOD;
	return a;
}

inline void Digital_DP(int dp[MAXN][MAXN][3], int num[])
{
	for (int i = 1; i <= num[1]; i++)
	{
		if (i < num[1]) dp[1][i % M][2]++;
		else if (i == num[1]) dp[1][i % M][1]++;
		else dp[1][i % M][0]++;
	}
	for (int i = 2; i <= n; i++)
	{
		if (i & 1)
		{
			for (int k = 0; k <= 9; k++)
				for (int j = 0; j < M; j++)
				{
					dp[i][(j * 10 + k) % M][0] = update(dp[i][(j * 10 + k) % M][0], dp[i - 1][j][0]);
					if (k < num[i]) dp[i][(j * 10 + k) % M][2] = update(dp[i][(j * 10 + k) % M][2], dp[i - 1][j][1]);
					else if (k == num[i]) dp[i][(j * 10 + k) % M][1] = update(dp[i][(j * 10 + k) % M][1], dp[i - 1][j][1]);
					else dp[i][(j * 10 + k) % M][0] = update(dp[i][(j * 10 + k) % M][0], dp[i - 1][j][1]);
					dp[i][(j * 10 + k) % M][2] = update(dp[i][(j * 10 + k) % M][2], dp[i - 1][j][2]);
				}
		}
		else
		{
			for (int j = 0; j < M; j++)
			{
				dp[i][(j * 10 + 7) % M][0] = update(dp[i][(j * 10 + 7) % M][0], dp[i - 1][j][0]);
				if (7 < num[i]) dp[i][(j * 10 + 7) % M][2] = update(dp[i][(j * 10 + 7) % M][2], dp[i - 1][j][1]);
				else if (7 == num[i]) dp[i][(j * 10 + 7) % M][1] = update(dp[i][(j * 10 + 7) % M][1], dp[i - 1][j][1]);
				else dp[i][(j * 10 + 7) % M][0] = update(dp[i][(j * 10 + 7) % M][0], dp[i - 1][j][1]);
				dp[i][(j * 10 + 7) % M][2] = update(dp[i][(j * 10 + 7) % M][2], dp[i - 1][j][2]);
			}
		}
	}
	return ;
}

int main()
{
	//freopen("luckynumber.in","r",stdin);freopen("luckynumber.out","w",stdout);
	scanf("%d", &M);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	if (n == 1)
	{
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; i++) L[i] = s[i] - '0';
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) R[i] = s[i] - '0';
	Digital_DP(dpL, L);
	Digital_DP(dpR, R);
	printf("%d\n", (dpR[n][0][2] + dpR[n][0][1] - dpL[n][0][2] + MOD) % MOD);
	return 0;
}