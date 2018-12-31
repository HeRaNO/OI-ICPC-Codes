#include <cstdio>
#define MAXN 21
using namespace std;

int n, a[MAXN];
int dp1[MAXN], dp2[MAXN];
int ans1, ans2;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	while (~scanf("%d", &a[++n]));
	dp1[1] = dp2[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++) if (a[j] > a[i]) dp1[i] = mymax(dp1[i], dp1[j]);
		dp1[i]++;
		ans1 = mymax(ans1, dp1[i]);
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++) if (a[j] < a[i]) dp2[i] = mymax(dp2[i], dp2[j]);
		dp2[i]++;
		ans2 = mymax(ans2, dp2[i]);
	}
	ans1--;
	ans2--;
	printf("%d %d\n", ans1, ans2);
	return 0;
}
