#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
#define MAXN 10010
#define MAXT 90010
using namespace std;

struct protect
{
	int from;
	int to;
	int val;
};

protect a[MAXN];
int c[MAXT], dp[MAXT];
int n, s, t;
int aa, bb, cc;

int lowbit(int x)
{
	return x & (-x);
}

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

bool cmp(protect a, protect b)
{
	if (a.from == b.from) return a.to < b.to;
	return a.from < b.from;
}

int find_min(int x)
{
	int ret = INT_MAX;
	for (int i = x; i; i -= lowbit(i))
		ret = mymin(ret, c[i]);
	return ret;
}

void add(int x, int delta)
{
	for (int i = x; i <= t + 1; i += lowbit(i))
		c[i] = mymin(c[i], delta);
	return ;
}

int main()
{
	memset(c, 0x7f, sizeof(c));
	scanf("%d %d %d", &n, &s, &t);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &aa, &bb, &cc);
		a[i].from = mymax(aa, s) - s + 1;
		a[i].to = mymin(bb, t) - s + 1;
		a[i].val = cc;
	}
	t = t - s + 1;
	sort(a + 1, a + n + 1, cmp);
	add(t + 1, 0);
	int j = n;
	for (int i = t; i; i--)
	{
		dp[i] = INT_MAX >> 1;
		while (j && a[j].from == i)
		{
			dp[i] = mymin(dp[i], find_min(a[j].to + 1) + a[j].val);
			j--;
		}
		add(i, dp[i]);
	}
	printf("%d\n", dp[1] == INT_MAX >> 1 ? -1 : dp[1]);
}