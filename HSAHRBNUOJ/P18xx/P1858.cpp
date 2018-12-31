#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;

int n, k;
int a[MAXN];

bool check(int lim)
{
	int cnt = 1, len = a[1];
	for (int i = 2; i <= n; i++)
	{
		if (a[i] - len < lim) continue;
		cnt++;
		len = a[i];
	}
	return cnt >= k;
}

int binary()
{
	int left = -1, right = 1e9 + 1, middle;
	while (left + 1 != right)
	{
		middle = (left + right) >> 1;
		if (check(middle)) left = middle;
		else right = middle;
	}
	return left;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	printf("%d\n", binary());
	return 0;
}
