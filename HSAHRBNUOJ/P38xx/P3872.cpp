#include <cstdio>
#define MAXN 100015
using namespace std;

double dp[MAXN], p[15];
int n, m, u, v;
int jump[MAXN];

int main()
{
	//freopen("dice.in","r",stdin);freopen("dice.out","w",stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		jump[u] = v;
	}
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
			p[i + j] += 1.0 / 36.0;
	for (int i = n - 1; ~i; i--)
	{
		if (jump[i]) dp[i] = dp[jump[i]];
		else
		{
			for (int j = 2; j <= 12; j++)
				dp[i] += (dp[i + j] + 1) * p[j];
		}
	}
	printf("%.4lf\n", dp[0]);
	return 0;
}
