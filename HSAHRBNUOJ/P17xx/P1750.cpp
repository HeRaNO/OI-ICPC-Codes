#include <cstdio>
#include <cstring>
#define MAXN 410
using namespace std;

int n, T, x;
int f[MAXN][MAXN];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline int query(int x1, int y1, int x2, int y2)
{
	return f[x2][y2] - f[x2][y1 - 1] - f[x1 - 1][y2] + f[x1 - 1][y1 - 1];
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
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	//freopen("bitmap2.in","r",stdin);freopen("bitmap2.out","w",stdout);
	read(T);
	while (T--)
	{
		read(n);
		memset(f, 0, sizeof f);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				read(f[i + n - j][j + i - 1]);
		for (int i = 1; i <= 2 * n; i++)
		{
			for (int j = 1; j <= 2 * n; j++) f[i][j] += f[i][j - 1];
			for (int j = 1; j <= 2 * n; j++) f[i][j] += f[i - 1][j];
		}
		for (int i = 1; i <= n; i++)
		{
			int j;
			for (j = 1; j < n; j++) read(x), printf("%d ", query(mymax(i + n - j - x, 1), mymax(j + i - 1 - x, 1), mymin(i + n - j + x, 2 * n), mymin(j + i - 1 + x, 2 * n)));
			read(x);
			printf("%d\n", query(mymax(i + n - j - x, 1), mymax(j + i - 1 - x, 1), mymin(i + n - j + x, 2 * n), mymin(j + i - 1 + x, 2 * n)));
		}
		if (T) puts("");
	}
	return 0;
}
