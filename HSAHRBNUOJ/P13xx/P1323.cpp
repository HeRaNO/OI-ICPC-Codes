#include <cstdio>
#define MAXN 1200
using namespace std;

int c[MAXN][MAXN];
int n, m;
int x1, x2, y1, y2;
int k;

int lowbit(int x)
{
	return x & (-x);
}

int sum(int x, int y)
{
	int ret = 0;
	for (int i = y; i; i -= lowbit(i))
		for (int j = x; j; j -= lowbit(j))
			ret += c[i][j];
	return ret;
}

void add(int x, int y, int delta)
{
	for (int i = y; i <= n; i += lowbit(i))
		for (int j = x; j <= n; j += lowbit(j))
			c[i][j] += delta;
	return ;
}

int main()
{
	scanf("%d", &n);
	while (scanf("%d", &m) != EOF)
	{
		if (m == 1)
		{
			scanf("%d %d %d", &x1, &y1, &k);
			add(x1 + 1, y1 + 1, k);
		}
		else if (m == 2)
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			printf("%d\n", sum(x2 + 1, y2 + 1) - sum(x1, y2 + 1) - sum(x2 + 1, y1) + sum(x1, y1));
		}
		else break;
	}
	return 0;
}
