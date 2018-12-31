#include <cstdio>
#define MAXN 50000
using namespace std;

int n, l, k;
int a[MAXN];

bool check(int limit)
{
	int cnt = 0, len = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] - len < limit)
		{
			cnt++;
			if (cnt > k) return false;
			continue;
		}
		len = a[i];
	}
	return cnt <= k;
}

int binary()
{
	int left = -1, right = l + 1, middle;
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
	scanf("%d %d %d", &l, &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	a[n + 1] = l;
	printf("%d\n", binary());
	return 0;
}
