#include <cstdio>
#include <cstring>
#define MAXN 2510
using namespace std;
//H:1 J:2
int a[MAXN], b[MAXN];
int dp[MAXN];
int n, d, flag1, flag2;
int aa;

int myabs(int a)
{
	return a > 0 ? a : -a;
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	memset(dp, 0x7f, sizeof(dp));
	dp[0] = 0;
	scanf("%d %d", &n, &d);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &aa);
		if (aa == 1) flag1++;
		else flag2++;
		a[i] = flag1;
		b[i] = flag2;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			if (myabs((a[i] - a[j]) - (b[i] - b[j])) <= d || a[i] == a[j] || b[i] == b[j])
				dp[i] = mymin(dp[i], dp[j] + 1);
	printf("%d\n", dp[n]);
	return 0;
}
