#include <cstdio>
#include <algorithm>
#define MAXN 210
#define MAXM 20000
using namespace std;

struct link
{
	int u, v, w;
};

struct Segment
{
	int l, r;
};

link e[MAXM];
Segment a[MAXN];
int n, m, u, v, w;
int dis[MAXN][MAXN];

bool cmp1(link a, link b)
{
	return a.w < b.w;
}

bool cmp2(Segment a, Segment b)
{
	if (a.l == b.l) return a.r < b.r;
	return a.l < b.l;
}

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void Floyed()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = mymin(dis[i][j], dis[i][k] + dis[k][j]);
	return ;
}

bool check(int limit)
{
	int left, right, nowl, nowr, cnt;
	for (int i = 1; i <= m; i++)
	{
		left = right = cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			nowl = mymax(0, limit - dis[j][e[i].u]);
			nowr = mymax(0, limit - dis[j][e[i].v]);
			if (!nowl && !nowr)
			{
				right = e[i].w;
				break;
			}
			a[++cnt] = (Segment)
			{
				mymin(nowl, e[i].w), mymax(e[i].w - nowr, 0)
			};
		}
		sort(a + 1, a + cnt + 1, cmp2);
		for (int j = 1; j <= cnt; j++)
		{
			if (a[j].l > a[j].r) continue;
			else if (a[j].l <= right) right = mymax(right, a[j].r);
			else if (right == e[i].w) break;
			else return true;
		}
		if (right < e[i].w) return true;
	}
	return false;
}

double binary()
{
	int left = 0, right = ~(1 << 31), middle;
	while (right - left > 1)
	{
		middle = (left + right) >> 1;
		if (check(middle)) right = middle;
		else left = middle;
	}
	return (double)left;
}

int main()
{
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
			dis[i][j] = 1e7;
		dis[i][i] = 0;
	}
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		e[i] = (link)
		{
			u, v, w * 2
		};
		dis[u][v] = dis[v][u] = mymin(dis[u][v], w * 2);
	}
	sort(e + 1, e + m + 1, cmp1);
	Floyed();
	printf("%.2lf", binary() / 2.0);
	return 0;
}
