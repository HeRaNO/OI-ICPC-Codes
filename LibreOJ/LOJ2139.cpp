#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105
using namespace std;

struct Point
{
	int x, y, c;
	bool operator < (const Point &a)const
	{
		return x == a.x ? y < a.y : x < a.x;
	}
};

Point a[MAXN], b[MAXN], r[MAXN], u[MAXN], d[MAXN];
int n, m, _R, lu, ld, lr, f[MAXN][MAXN][MAXN], ans = ~(1 << 31);
long long R;

inline bool in(Point a, Point b)
{
	long long x = a.x - b.x, y = a.y - b.y;
	return x * x + y * y <= R * R;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	bool f = false;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	if (f) x = -x;
	return ;
}

int main()
{
	memset(f, 0x7f, sizeof f);
	f[0][0][0] = 0;
	read(n);
	read(m);
	read(_R);
	R = _R;
	for (int i = 1; i <= n; i++) read(a[i].x), read(a[i].y);
	for (int i = 1; i <= m; i++) read(b[i].x), read(b[i].y), read(b[i].c);
	for (int i = 1; i <= n; i++)
	{
		bool f = false;
		for (int j = 1; j <= m && !f; j++)
			if (in(a[i], b[j])) f = true;
		if (f) r[++lr] = a[i];
	}
	printf("%d\n", lr);
	sort(r + 1, r + lr + 1);
	for (int i = 1; i <= m; i++)
		if (b[i].y < 0) d[++ld] = b[i];
		else u[++lu] = b[i];
	for (int i = 1; i <= lu; i++) f[0][i][0] = f[0][i - 1][0] + u[i].c;
	for (int i = 1; i <= ld; i++) f[0][0][i] = f[0][0][i - 1] + d[i].c;
	for (int i = 1; i <= lu; i++)
		for (int j = 1; j <= ld; j++)
			f[0][i][j] = f[0][i][0] + f[0][0][j];
	for (int i = 1; i <= lr; i++)
		for (int j = 0; j <= lu; j++)
			for (int k = 0; k <= ld; k++)
			{
				if (in(r[i], u[j]) && j)
				{
					f[i][j][k] = min(f[i][j][k], f[i - 1][j][k]);
					for (int l = 0; l <= lu; l++) f[i][j][k] = min(f[i][j][k], f[i - 1][l][k] + u[j].c);
				}
				if (in(r[i], d[k]) && k)
				{
					f[i][j][k] = min(f[i][j][k], f[i - 1][j][k]);
					for (int l = 0; l <= ld; l++) f[i][j][k] = min(f[i][j][k], f[i - 1][j][l] + d[k].c);
				}
			}
	for (int i = 0; i <= lu; i++)
		for (int j = 0; j <= ld; j++)
			ans = min(ans, f[lr][i][j]);
	printf("%d\n", ans);
	return 0;
}
