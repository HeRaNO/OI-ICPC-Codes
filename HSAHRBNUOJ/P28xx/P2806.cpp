#include <cstdio>
#include <algorithm>
#define MAXN 2010
using namespace std;

int n, T;
long long a[MAXN][MAXN], b[MAXN][MAXN];
long long res[MAXN][MAXN];
long long sumb[MAXN];
int x1, x2, y11, y2;

inline void read(long long &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10LL + ch - '0', ch = getchar();
	x *= f;
	return ;
}

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10LL + ch - '0', ch = getchar();
	x *= f;
	return ;
}

long long query(int x, int y)
{
	long long res = 0LL;
	for (int i = 1; i <= n; i++) res += a[x][i] * b[i][y];
	return res;
}

int main()
{
	//freopen("matrix.in","r",stdin);freopen("matrix.out","w",stdout);
	read(n);
	read(T);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			read(a[i][j]);
			a[i][j] += a[i - 1][j];
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			read(b[i][j]);
			b[i][j] += b[i][j - 1];
		}
	while (T--)
	{
		read(x1);
		read(y11);
		read(x2);
		read(y2);
		if (x1 > x2) swap(x1, x2);
		if (y11 > y2) swap(y11, y2);
		printf("%lld\n", query(x2, y2) - query(x2, y11 - 1) - query(x1 - 1, y2) + query(x1 - 1, y11 - 1));
	}
	return 0;
}
