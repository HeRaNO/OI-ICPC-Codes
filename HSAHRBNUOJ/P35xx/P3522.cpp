#include <cstdio>
#include <algorithm>
#define MAXN 100010
#define INT_MIN -2147483648
using namespace std;

int n, ans;
pair <int, int> a[MAXN];
int d[MAXN];

int binary(int x)
{
	int left = 0, right = ans, middle;
	while (left < right)
	{
		middle = (left + right) >> 1;
		if (d[middle] <= x) left = middle + 1;
		else right = middle;
	}
	return left;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d %d", &a[i].first, &a[i].second);
	sort(a + 1, a + n + 1);
	d[0] = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		if (a[i].first < 0 || a[i].second < 0) continue;
		if (a[i].second >= d[ans]) d[++ans] = a[i].second;
		else d[binary(a[i].second)] = a[i].second;
	}
	printf("%d\n", ans);
	return 0;
}
