#include <cstdio>
#define MAXN 200000

int n;
int a[MAXN];
int best, ans;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		best += a[i];
		if (best < 0) best = 0;
		ans = mymax(ans, best);
	}
	printf("%d\n", ans);
	return 0;
}
