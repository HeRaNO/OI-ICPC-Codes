#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;

int n, t, q;
int a[MAXN];
int ans;

int myabs(int a)
{
	return a > 0 ? a : -a;
}

int binary(int x)
{
	int left = 0, right = n, middle;
	while (left + 1 != right)
	{
		middle = (right + left) >> 1;
		if (a[middle] == x) return a[middle];
		else if (a[middle] < x) left = middle;
		else right = middle;
	}
	if (!left) return a[right];
	if (x - a[left] > a[right] - x) return a[right];
	else return a[left];
}

int main()
{
	scanf("%d %d", &n, &t);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	while (t--)
	{
		scanf("%d", &q);
		ans += myabs(q - binary(q));
	}
	printf("%d\n", ans);
	return 0;
}
