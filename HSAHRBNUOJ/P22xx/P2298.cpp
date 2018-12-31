#include <cstdio>
#define MAXN 110
using namespace std;

int a[MAXN];
int dp1[MAXN], dp2[MAXN];
int ans, n;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int myabs(int a)
{
	return a > 0 ? a : -a;
}

int get(int l, int r)
{
	if (l == r) return a[l];
	if (l > r) return 0;
	else return myabs(a[l] - a[r]) * (r - l + 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp1[i] = mymax(dp1[i], dp1[j - 1] + get(j, i));
	for (int i = n; i >= 1; i--)
		for (int j = n; j >= i; j--)
			dp2[i] = mymax(dp2[i], dp2[j + 1] + get(i, j));
	for (int i = n; i >= 1; i--)
		ans = mymax(ans, dp2[i] + dp1[i - 1]);
	printf("%d\n", ans);
	return 0;
}
