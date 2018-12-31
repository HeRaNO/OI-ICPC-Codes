#include <cstdio>
#define MAXN 6

int aa[MAXN], bb[MAXN], cc[MAXN], p[MAXN];
int a[MAXN], b[MAXN], c[MAXN], t[MAXN];
int n, x, y, ans;
bool vis[MAXN];

inline void max(int &a, int b)
{
	if (a < b) a = b;
	return ;
}

void dfs(int dep)
{
	if (dep == n + 1)
	{
		int h = 0, d = 0, t = 0;
		for (int i = 1; i <= n; i++)
		{
			h += a[p[i]];
			t += b[p[i]];
			d += c[p[i]];
		}
		if (t > x) h = -1;
		if (d > y) h = -1;
		max(ans, h);
		return ;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i])
		{
			vis[i] = true;
			p[dep] = i;
			dfs(dep + 1);
			vis[i] = false;
		}
	return ;
}

int main()
{
	scanf("%d %d %d", &n, &x, &y);
	for (int i = 1; i <= 5; i++) scanf("%d %d %d", &aa[i], &bb[i], &cc[i]);
	for (int sta = 1; sta <= 31; sta++)
	{
		n = 0;
		for (int i = 0; i < 5; i++)
		{
			if (sta & (1 << i)) t[++n] = i + 1;
		}
		for (int i = 1; i <= n; i++)
		{
			a[i] = aa[t[i]];
			b[i] = bb[t[i]];
			c[i] = cc[t[i]];
		}
		dfs(1);
	}
	printf("%d\n", ans);
	return 0;
}
