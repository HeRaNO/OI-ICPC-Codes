#include <cstdio>
#include <cstring>
#define MAXN 105
using namespace std;

int n, T, a[MAXN][MAXN], dis[MAXN][MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void read(int &x)
{
	x = 0;
	bool f = false;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(T);
	while (T--)
	{
		read(n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				dis[i][j] = 1e9;
				read(a[i][j]);
				if (i == j) a[i][j] = 1e9;
			}
		for (int u = 1; u <= n; u++)
			for (int v = 1; v <= n; v++)
			{
				bool f = false;
				for (int w = 1; w <= n && !f; w++) if (a[u][w] + a[w][v] == a[u][v]) f = true;
				if (!f) dis[u][v] = a[u][v];
			}
		for (int i = 1; i <= n; i++) dis[i][i] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (dis[i][j] == 1e9) printf("infty%c", j == n ? '\n' : ' ');
				else printf("%d%c", dis[i][j], j == n ? '\n' : ' ');
			}
	}
	return 0;
}