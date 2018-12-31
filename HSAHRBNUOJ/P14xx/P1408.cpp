#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXK 1010
using namespace std;

int n, m, k, t;
pair <int, int> a[MAXK];
int dp[MAXK];
double ans;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) scanf("%d %d", &a[i].first, &a[i].second);
	sort(a + 1, a + k + 1);
	for (int i = 1; i <= k; i++) dp[i] = 1;
	for (int i = 1; i <= k; i++)
		for (int j = i + 1; j <= k; j++)
			if (a[j].first > a[i].first && a[j].second > a[i].second)
				dp[j] = mymax(dp[j], dp[i] + 1);
	for (int i = 1; i <= k; i++) t = mymax(t, dp[i]);
	ans = (double)(n + m) * 100.0 - (double)t * (200.0 - 100.0 * sqrt(2));
	printf("%.0lf\n", ans);
	return 0;
}
