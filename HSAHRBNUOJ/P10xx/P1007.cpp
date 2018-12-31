#include <cstdio>
#define MAXN 20010
#define MAXM 110
#define INT_MIN -2147483648
using namespace std;

int n, m, t, ans;
int dp[MAXN], a[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	for (int i = 1; i < MAXN; i++) dp[i] = a[i] = INT_MIN;
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j < n; j++)
		{
			scanf("%d", &t);
			a[j] = mymax(a[j], t);
		}
	for (int i = 1; i < n; i++) dp[i] = mymax(dp[i - 1] + a[i], a[i]), ans = mymax(ans, dp[i]);
	printf("%d\n", ans);
	return 0;
}
