#include <cstdio>
#include <cstring>
#define MAXN 1010
#define REBUILD 1000
using namespace std;

struct query
{
	int x, y, l;
};

query a[MAXN];
int n, T, cnt, u, v, w, opt;
int lazy[MAXN][MAXN];
long long c[MAXN][MAXN];

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void clean()
{
	memset(lazy, 0, sizeof lazy);
	while (cnt)
	{
		for (int i = a[cnt].y, j = a[cnt].x; i < a[cnt].y + a[cnt].l; i++, j++)
			lazy[i][j]++, lazy[i][a[cnt].x + a[cnt].l]--;
		cnt--;
	}
	for (int i = 1; i <= n; i++)
	{
		long long t = 0, tt = 0;
		for (int j = i; j <= n; j++)
		{
			t += lazy[i][j];
			tt += t;
			c[i][j] += tt;
		}
	}
	return ;
}

long long sumit(int x, int y, int r)
{
	long long res = 0LL;
	for (int i = y, j = x - 1; i < y + r; i++, j++) res += c[i][x + r - 1] - c[i][j];
	for (int i = 1; i <= cnt; i++)
	{
		int xx = mymin(x + r - 1, a[i].x + a[i].l - 1);
		int yy = mymax(y, a[i].y);
		int rr = mymax(x - y, a[i].x - a[i].y);
		if (x > xx || a[i].x > xx) continue;
		if (y + r - 1 < yy || a[i].y + a[i].l - 1 < yy) continue;
		if (x + r - 1 - y < rr || a[i].x + a[i].l - 1 - a[i].y < rr) continue;
		long long len = xx - yy - rr + 1;
		res += len * (len + 1) / 2;
	}
	return res;
}

int main()
{
	//freopen("delta.in","r",stdin);freopen("delta.out","w",stdout);
	n = read();
	T = read();
	while (T--)
	{
		opt = read();
		opt--;
		if (!opt)
		{
			u = read();
			v = read();
			w = read();
			cnt++;
			a[cnt] = (query)
			{
				u, v, w
			};
			if (cnt == REBUILD) clean();
		}
		else
		{
			u = read();
			v = read();
			w = read();
			printf("%lld\n", sumit(u, v, w));
		}
	}
	return 0;
}
