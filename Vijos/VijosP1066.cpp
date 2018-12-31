#include <cstdio>
#include <algorithm>
#define MAXN 32010
using namespace std;

struct point
{
	int x, y;
};

point in[MAXN];
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
}

bool cmp(point a, point b)
{
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &in[i].x, &in[i].y);
	sort(in + 1, in + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		int level = sum(in[i].x);
		ans[level]++;
		add(in[i].x, MAXN, 1);
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", ans[i]);
	return 0;
}
