#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define MAXN 20010
#define MAXM 100010
using namespace std;

struct thief
{
	int first;
	int second;
	int anger;
};

thief a[MAXM];
int father[2 * MAXN];
int i, n, m;
int tmp1, tmp2, tmp3, tmp4;

bool cmp(const thief &x, const thief &y)
{
	return x.anger > y.anger;
}

int getfather(int v)
{
	return father[v] == v ? v : getfather(father[v]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++)
		scanf("%d %d %d", &a[i].first, &a[i].second, &a[i].anger);
	for (i = 1; i <= 2 * n; i++)
		father[i] = i;
	sort(a + 1, a + m + 1, cmp);
	for (i = 1; i <= m; i++)
	{
		tmp1 = getfather(a[i].first);
		tmp2 = getfather(a[i].second);
		if (tmp1 != tmp2)
		{
			tmp3 = getfather(a[i].first + n);
			if (tmp3 != tmp2)
				father[tmp3] = tmp2;
			tmp4 = getfather(a[i].second + n);
			if (tmp1 != tmp4)
				father[tmp1] = tmp4;
		}
		else
		{
			printf("%d\n", a[i].anger);
			exit(0);
		}
	}
	printf("0\n");
	return 0;
}
