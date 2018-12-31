#include <cstdio>
#include <cstring>
#define MAXN 505
using namespace std;

const int d[4][2] =
{
	{1, 0}, {-1, 0},
	{0, 1}, {0, -1}
};

int a[MAXN][MAXN], f[MAXN * MAXN];
int n, T, c, x, y, tx, ty, fx, fy, ans;

inline int getf(int x)
{
	return x == f[x] ? x : f[x] = getf(f[x]);
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
	memset(a, -1, sizeof a);
	read(n);
	read(T);
	for (int i = 1; i <= n * n; i++) f[i] = i;
	while (T--)
	{
		read(c);
		read(x);
		read(y);
		a[x][y] = c;
		ans++;
		for (int i = 0; i < 4; i++)
		{
			tx = x + d[i][0];
			ty = y + d[i][1];
			if (tx > n || ty > n || ty < 1 || tx < 1) continue;
			if (a[tx][ty] == a[x][y])
			{
				fx = getf((tx - 1) * n + ty);
				fy = getf((x - 1) * n + y);
				if (fx != fy)
				{
					f[fx] = fy;
					ans--;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}