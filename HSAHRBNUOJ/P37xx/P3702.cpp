#include <cstdio>
#include <algorithm>
#define MAXN 50010
using namespace std;

struct edge
{
	int x, y, w, c;
	bool operator < (const edge &a)const
	{
		return w == a.w ? c > a.c : w < a.w;
	}
};

edge e[MAXN << 1];
int f[MAXN], n, m, a, b, t, tp, ans;

inline int getf(int x)
{
	return x == f[x] ? x : f[x] = getf(f[x]);
}

inline int check(int x)
{
	int fx, fy, cnt = 0, white = 0;
	ans = 0;
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++) if (!e[i].c) e[i].w += x;
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; i++)
	{
		fx = getf(e[i].x);
		fy = getf(e[i].y);
		if (fx != fy)
		{
			f[fy] = fx;
			ans += e[i].w;
			++cnt;
			if (!e[i].c) ++white;
			if (cnt == n - 1) break;
		}
	}
	for (int i = 1; i <= m; i++) if (!e[i].c) e[i].w -= x;
	return white;
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
	read(n);
	read(m);
	read(t);
	for (int i = 1; i <= m; i++)
	{
		read(e[i].x);
		read(e[i].y);
		read(e[i].w);
		read(e[i].c);
		++e[i].x;
		++e[i].y;
	}
	a = check(-105);
	for (int i = -104; i <= 105; i++)
	{
		b = check(i);
		if (b <= t && t <= a)
		{
			printf("%d\n", ans - i * t);
			return 0;
		}
		tp = a;
		a = b;
		b = tp;
	}
	return 0;
}