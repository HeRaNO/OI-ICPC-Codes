#include <cstdio>
#include <cstring>
#include <algorithm>
#define PO 10000
#define MAXN 10000
using namespace std;

struct scan
{
	int ck, pos, st, ed;
};

scan x[MAXN], y[MAXN];
int xx[MAXN * 2], yy[MAXN * 2];
int lenx[MAXN], leny[MAXN];
int vis[MAXN];
int x1, x2, y11, y2;
int tx, ty, ans, n;

bool cmp(scan a, scan b)
{
	return a.ck < b.ck;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &x1, &y11, &x2, &y2);
		x1 += PO;
		x2 += PO;
		y11 += PO;
		y2 += PO;
		xx[x1] = xx[x2] = yy[y11] = yy[y2] = 1;
		x[i * 2].ck = y11;
		x[i * 2].pos = 1;
		x[i * 2].st = x1;
		x[i * 2].ed = x2;
		x[i * 2 + 1].ck = y2;
		x[i * 2 + 1].pos = -1;
		x[i * 2 + 1].st = x1;
		x[i * 2 + 1].ed = x2;
		y[i * 2].ck = x1;
		y[i * 2].pos = 1;
		y[i * 2].st = y11;
		y[i * 2].ed = y2;
		y[i * 2 + 1].ck = x2;
		y[i * 2 + 1].pos = -1;
		y[i * 2 + 1].st = y11;
		y[i * 2 + 1].ed = y2;
	}
	sort(x, x + 2 * n, cmp);
	sort(y, y + 2 * n, cmp);
	for (int i = 0; i < 2 * PO; i++)
	{
		if (xx[i])
		{
			xx[i] = tx;
			lenx[tx++] = i;
		}
		if (yy[i])
		{
			yy[i] = ty;
			leny[ty++] = i;
		}
	}
	for (int i = 0; i < 2 * n; i++)
	{
		x[i].st = xx[x[i].st];
		x[i].ed = xx[x[i].ed];
		y[i].st = yy[y[i].st];
		y[i].ed = yy[y[i].ed];
	}
	memset(vis, 0, sizeof vis);
	for (int i = 0; i < 2 * n; i++)
		for (int j = x[i].st; j < x[i].ed; j++)
		{
			vis[j] += x[i].pos;
			if (vis[j] == 0) ans += lenx[j + 1] - lenx[j];
		}
	memset(vis, 0, sizeof vis);
	for (int i = 0; i < 2 * n; i++)
		for (int j = y[i].st; j < y[i].ed; j++)
		{
			vis[j] += y[i].pos;
			if (vis[j] == 0) ans += leny[j + 1] - leny[j];
		}
	printf("%d\n", ans << 1);
	return 0;
}
