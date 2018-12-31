#include <cstdio>
#include <algorithm>
#define MAXN 200010
using namespace std;

int a[MAXN];
int n, s;
long long ans;

long long binary(int x)
{
	int left = x, right = n;
	int middle, q = s - a[left];
	while (right - left != 1)
	{
		middle = (right + left) >> 1;
		if (a[middle] <= q) left = middle;
		else right = middle;
	}
	return n - left - 1;
}

int main()
{
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		ans += binary(i);
	printf("%lld\n", ans);
	return 0;
}
