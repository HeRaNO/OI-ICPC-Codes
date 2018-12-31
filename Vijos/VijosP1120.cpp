#include <cstdio>
#include <algorithm>
#define MAXN 410
using namespace std;

struct peanuts
{
	int x;
	int y;
	int num;
};

peanuts a[MAXN];
int in, cnt;
int n, m, k;
int nowx, nowy;
int ans, time;

int myabs(int a)
{
	return a > 0 ? a : -a;
}

bool cmp(peanuts a, peanuts b)
{
	return a.num > b.num;
}

int main()
{
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &in);
			if (in)
			{
				a[++cnt].x = i;
				a[cnt].y = j;
				a[cnt].num = in;
			}
		}
	sort(a + 1, a + cnt + 1, cmp);
	nowy = a[1].y;
	for (int i = 1; i <= cnt; i++)
	{
		if (time + myabs(a[i].x - nowx) + myabs(a[i].y - nowy) + a[i].x + 1 <= k)
		{
			time += myabs(a[i].x - nowx) + myabs(a[i].y - nowy) + 1;
			ans += a[i].num;
			nowx = a[i].x;
			nowy = a[i].y;
		}
		else break;
	}
	printf("%d\n", ans);
	return 0;
}
