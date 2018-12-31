#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 1010
using namespace std;

int g[MAXN][MAXN];
int n, x[MAXN][MAXN], y[MAXN][MAXN];
int sx, sy, tx, ty;
int dis[MAXN * MAXN];
bool vis[MAXN * MAXN];
queue <pair<int, int> > q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

inline void bfs()
{
	q.push(make_pair(sx, sy));
	dis[(sx - 1)*n + sy] = 0;
	while (!q.empty())
	{
		pair<int, int> u = q.front();
		q.pop();
		int xx = u.first, yy = u.second;
		if (xx == tx && yy == ty) return ;
		for (int i = 1; i <= x[xx][0]; i++)
		{
			if (x[xx][i] > yy)
			{
				int ty = x[xx][i] - 1;
				if (dis[(xx - 1)*n + ty] > dis[(xx - 1)*n + yy] + 1)
				{
					dis[(xx - 1)*n + ty] = dis[(xx - 1) * n + yy] + 1;
					q.push(make_pair(xx, ty));
				}
				break;
			}
		}
		for (int i = x[xx][0]; i; i--)
		{
			if (x[xx][i] < yy)
			{
				int ty = x[xx][i] + 1;
				if (dis[(xx - 1)*n + ty] > dis[(xx - 1)*n + yy] + 1)
				{
					dis[(xx - 1)*n + ty] = dis[(xx - 1) * n + yy] + 1;
					q.push(make_pair(xx, ty));
				}
				break;
			}
		}
		for (int i = 1; i <= y[yy][0]; i++)
		{
			if (y[yy][i] > xx)
			{
				int tx = y[yy][i] - 1;
				if (dis[(tx - 1)*n + yy] > dis[(xx - 1)*n + yy] + 1)
				{
					dis[(tx - 1)*n + yy] = dis[(xx - 1) * n + yy] + 1;
					q.push(make_pair(tx, yy));
				}
				break;
			}
		}
		for (int i = y[yy][0]; i; i--)
		{
			if (y[yy][i] < xx)
			{
				int tx = y[yy][i] + 1;
				if (dis[(tx - 1)*n + yy] > dis[(xx - 1)*n + yy] + 1)
				{
					dis[(tx - 1)*n + yy] = dis[(xx - 1) * n + yy] + 1;
					q.push(make_pair(tx, yy));
				}
				break;
			}
		}
	}
}

int main()
{
	memset(dis, 0x7f, sizeof dis);
	read(n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			read(g[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (g[i][j]) x[i][++x[i][0]] = j;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (g[j][i]) y[i][++y[i][0]] = j;
	read(sx);
	read(sy);
	read(tx);
	read(ty);
	bfs();
	if (dis[(tx - 1)*n + ty] == 0x7f7f7f7f) puts("impossible");
	else printf("%d\n", dis[(tx - 1)*n + ty]);
	return 0;
}
