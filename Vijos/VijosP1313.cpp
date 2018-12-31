#include<cstdio>
#define MAXN 32010
#define MAXM 61
using namespace std;

int v[MAXM], p[MAXM], q[MAXM];
int dp[MAXN];
int n, m, l, fj1, fj2;
bool flag1, flag2;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &v[i], &p[i], &q[i]);
	for (int i = 1; i <= m; i++)
	{
		fj1 = 0;
		fj2 = 0;
		flag1 = false;
		flag2 = false;
		if (!q[i])
		{
			int k;
			for (k = i + 1; k <= m; k++)
				if (q[k] == i)
				{
					fj1 = k;
					flag1 = true;
					break;
				}
			for (int l = k + 1; l <= m; l++)
				if (q[l] == i)
				{
					fj2 = l;
					flag2 = true;
					break;
				}
			for (int j = n; j >= v[i]; j--)
			{
				dp[j] = mymax(dp[j - v[i]] + v[i] * p[i], dp[j]);
				if ((j - v[i] - v[fj1] >= 0) && flag1)
					dp[j] = mymax(dp[j - v[i] - v[fj1]] + v[i] * p[i] + v[fj1] * p[fj1], dp[j]);
				if ((j - v[i] - v[fj2] >= 0) && flag2)
					dp[j] = mymax(dp[j - v[i] - v[fj2]] + v[i] * p[i] + v[fj2] * p[fj2], dp[j]);
				if ((j - v[i] - v[fj1] - v[fj2] >= 0) && flag2 && flag1)
					dp[j] = mymax(dp[j - v[i] - v[fj1] - v[fj2]] + v[i] * p[i] + v[fj1] * p[fj1] + v[fj2] * p[fj2], dp[j]);
			}
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}
