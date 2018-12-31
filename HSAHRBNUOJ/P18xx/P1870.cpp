#include <cstdio>
#define MAXN 800010
using namespace std;

int n;
double v, dp[MAXN][3];

double mymax(double a, double b)
{
	return a > b ? a : b;
}

int main()
{
	//freopen("cat.in","r",stdin);freopen("cat.out","w",stdout);
	scanf("%d", &n);
	for (int i = 2; i <= n + 1; i++)
	{
		scanf("%lf", &v);
		dp[i][0] = mymax(mymax(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
		dp[i][1] = mymax(dp[i - 1][0], dp[i - 1][1]) + v;
		dp[i][2] = mymax(dp[i - 1][0], dp[i - 1][1]) + v * v;
	}
	printf("%.4lf\n", mymax(mymax(dp[n + 1][0], dp[n + 1][1]), dp[n + 1][2]));
	return 0;
}
