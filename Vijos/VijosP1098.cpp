#include <cstdio>
#define MAXN 110
using namespace std;

int n, ans;
int a[MAXN], dp1[MAXN], dp2[MAXN];

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	dp1[1] = dp2[n] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			if (a[j] < a[i]) dp1[i] = mymax(dp1[j], dp1[i]);
		dp1[i]++;
	}
	for (int i = n - 1; i; i--)
	{
		for (int j = n; j >= i; j--)
			if (a[j] < a[i]) dp2[i] = mymax(dp2[i], dp2[j]);
		dp2[i]++;
	}
	for (int i = 1; i <= n; i++) ans = mymax(ans, dp1[i] + dp2[i] - 1);
	printf("%d\n", n - ans);
	return 0;
}
