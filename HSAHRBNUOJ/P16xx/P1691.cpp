#include <cstdio>
#include <cstring>
#define MAXN 10010
using namespace std;

int l1, l2, l3, c1, c2, c3;
int n, a, b, d, x;
int dis[MAXN], dp[MAXN];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	memset(dp, 0x7f, sizeof dp);
	scanf("%d %d %d %d %d %d", &l1, &l2, &l3, &c1, &c2, &c3);
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	dp[a] = 0;
	dis[1] = 0;
	for (int i = 2; i <= n; i++) scanf("%d", &dis[i]);
	for (int i = a + 1; i <= b; i++)
		for (int j = i - 1; j >= a; j--)
		{
			d = dis[i] - dis[j];
			if (d <= l1) x = c1;
			else if (d <= l2) x = c2;
			else if (d <= l3) x = c3;
			else break;
			dp[i] = mymin(dp[i], dp[j] + x);
		}
	printf("%d\n", dp[b]);
	return 0;
}
