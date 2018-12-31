//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXN 110
using namespace std;

int a[MAXN];
int dp1[MAXN], dp2[MAXN];
int ans1, ans2, n, maxl;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		memset(a, 0, sizeof(a));
		ans1 = 0;
		ans2 = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		dp1[1] = 1;
		dp2[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			maxl = 0;
			for (int j = 1; j <= i; j++)
				if (maxl < dp1[j] && a[j] > a[i]) maxl = dp1[j];
			dp1[i] = maxl + 1;
			ans1 = mymax(ans1, dp1[i]);
		}
		for (int i = 2; i <= n; i++)
		{
			maxl = 0;
			for (int j = 1; j <= i; j++)
				if (maxl < dp2[j] && a[j] < a[i]) maxl = dp2[j];
			dp2[i] = maxl + 1;
			ans2 = mymax(ans2, dp2[i]);
		}
		printf("%d\n", mymax(ans2, ans1));
	}
	return 0;
}
