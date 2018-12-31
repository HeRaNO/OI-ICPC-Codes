#include <cstdio>
#define MAXN 41
using namespace std;

const int d[4][2] =
{
	{1, 0}, {-1, 0},
	{0, 1}, {0, -1}
};

int x = 1, y = 1, n, m, a[MAXN][MAXN], ans;

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
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]);
	ans = a[1][1];
	a[1][1] = 0;
	while (!(x == n && y == m))
	{
		int mx = 0;
		for (int i = 1; i < 4; i++)
			if (a[x + d[i][0]][y + d[i][1]] > a[x + d[mx][0]][y + d[mx][1]])
				mx = i;
		x += d[mx][0];
		y += d[mx][1];
		ans += a[x][y];
		a[x][y] = 0;
	}
	printf("%d\n", ans + a[n][m]);
	return 0;
}