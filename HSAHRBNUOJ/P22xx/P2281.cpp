#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 3010
#define MOD 10000007
using namespace std;

struct link
{
	int val, nxt;
};

struct point
{
	int x, y;
	bool operator < (const point &b)const
	{
		return y == b.y ? x < b.x : y < b.y;
	}
};

point a[MAXN];
link e[MAXN];
int n, siz, xm, ym, dx, dy, nx, ny;
int head[MOD], cnt;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
inline int sqr(int a)
{
	return a * a;
}

inline void add(int x, int y)
{
	int hs = x * 100000 + y;
	e[cnt] = (link)
	{
		hs, head[hs % MOD]
	};
	head[hs % MOD] = cnt++;
	return ;
}

inline bool judge(int x, int y)
{
	int hs = x * 100000 + y;
	for (int i = head[hs % MOD]; ~i; i = e[i].nxt)
		if (e[i].val == hs) return true;
	return false;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	memset(head, -1, sizeof head);
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(a[i].x);
		read(a[i].y);
		a[i].x <<= 1;
		a[i].y <<= 1;
		add(a[i].x, a[i].y);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			xm = (a[i].x + a[j].x) >> 1;
			ym = (a[i].y + a[j].y) >> 1;
			dx = xm - a[i].x;
			dy = ym - a[i].y;
			nx = xm + dy;
			ny = ym - dx;
			if (nx < 0 || nx < 0 || nx > 10000 || ny > 10000) continue;
			if (!judge(nx, ny)) continue;
			nx = xm - dy;
			ny = ym + dx;
			if (nx < 0 || nx < 0 || nx > 10000 || ny > 10000) continue;
			if (!judge(nx, ny)) continue;
			siz = mymax(siz, (sqr(a[j].y - a[i].y) + sqr(a[j].x - a[i].x)) >> 1);
		}
	printf("%d\n", siz >> 2);
	return 0;
}