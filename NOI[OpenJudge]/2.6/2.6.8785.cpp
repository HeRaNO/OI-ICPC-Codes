//Code By HeRaNO
#include <cstdio>
#define MAXN 35
#define MAXV 20010
using namespace std;

int n, v;
int a, dp[MAXV];

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &v);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		for (int j = v; j >= a; j--)
			dp[j] = mymax(dp[j], dp[j - a] + a);
	}
	printf("%d\n", v - dp[v]);
	return 0;
}
