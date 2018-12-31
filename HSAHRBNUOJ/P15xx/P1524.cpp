#include <cstdio>
#include <cstring>
#define MAXN 105
using namespace std;

int n, u, v, c, g[MAXN][MAXN];
int ans = ~(1 << 31), now, x1, x2;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void Floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				g[i][j] = mymin(g[i][j], g[i][k] + g[k][j]);
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch;
	if ((ch = getchar()) == EOF)
	{
		x = 0;
		return ;
	}
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) g[i][j] = 100000000;
		g[i][i] = 0;
	}
	while (true)
	{
		read(u);
		if (!u) break;
		read(v);
		read(c);
		g[u][v] = mymin(g[u][v], c);
		g[v][u] = g[u][v];
	}
	Floyd();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			now = 0;
			for (int k = 1; k <= n; k++) now = mymax(now, mymin(g[i][k], g[j][k]));
			if (now < ans)
			{
				ans = now;
				x1 = i;
				x2 = j;
			}
		}
	printf("%d %d\n", x1, x2);
	return 0;
}