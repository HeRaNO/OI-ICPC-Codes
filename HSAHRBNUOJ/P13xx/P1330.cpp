#include <cstdio>
#define MAXN 32010
using namespace std;

int c[MAXN], ans[MAXN];
int n, m;
int x, y;
int k;

int lowbit(int x)
{
	return x & (-x);
}

int sum(int x)
{
	int ret = 0;
	for (int i = x; i; i -= lowbit(i))
		ret += c[i];
	return ret;
}

void add(int x, int y, int delta)
{
	for (int i = x; i <= y; i += lowbit(i))
		c[i] += delta;
	return ;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &x, &y);
		int level = sum(x + 1);
		ans[level]++;
		add(x + 1, MAXN, 1);
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i]);
	return 0;
}
