#include <cstdio>
#include <cstring>
#define MAXN 40010
#define MOD 10000007
using namespace std;

struct Hashlink
{
	int x, y, nxt;
};

struct point
{
	int x, y;
};

Hashlink e[MAXN];
int edge_num[MOD], cnt;
int n, ans;
int xm, ym, x2, y2, x3, y3;
point a[MAXN];

inline int myabs(int a)
{
	return a > 0 ? a : -a;
}
inline void add(int x, int y)
{
	int dis = (x * x + y * y) % MOD;
	e[cnt] = (Hashlink)
	{
		x, y, edge_num[dis]
	};
	edge_num[dis] = cnt++;
	return ;
}

inline bool exist(int x, int y)
{
	int dis = (x * x + y * y) % MOD;
	for (int i = edge_num[dis]; ~i; i = e[i].nxt)
		if (e[i].x == x && e[i].y == y) return true;
	return false;
}

int main()
{
	memset(edge_num, -1, sizeof edge_num);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a[i].x, &a[i].y);
		add(a[i].x, a[i].y);
	}
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			xm = a[i].x + a[j].x;
			ym = a[i].y + a[j].y;
			x2 = xm + a[j].y - a[i].y;
			y2 = ym + a[i].x - a[j].x;
			x3 = xm + a[i].y - a[j].y;
			y3 = ym + a[j].x - a[i].x;
			if ((myabs(x2) & 1) || (myabs(y2) & 1) || (myabs(x3) & 1) || (myabs(y3) & 1)) continue;
			x2 /= 2;
			x3 /= 2;
			y2 /= 2;
			y3 /= 2;
			if (exist(x3, y3) && exist(x2, y2)) ans++;
		}
	printf("%d\n", ans >> 1);
	return 0;
}
