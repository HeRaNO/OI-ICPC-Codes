#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 310
using namespace std;

const int d[4][2] =
{
	{1, 0}, {-1, 0},
	{0, 1}, {0, -1}
};
int n, m, sx, sy;
long long ans;
long long g[MAXN][MAXN];
long long dis[MAXN * MAXN];
queue <pair<pair<int, int>, int> > q;

inline long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

inline void read(long long &x)
{
	x = 0LL;
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

inline long long BFS()
{
	q.push(make_pair(make_pair(sx, sy), 0));
	while (!q.empty())
	{
		pair<pair<int, int>, int> u = q.front();
		q.pop();
		pair<int, int> pos = u.first;
		int x = pos.first, y = pos.second;
		if (u.second == 23) return ans;
		for (int i = 0; i < 4; i++)
		{
			int tx = x + d[i][0], ty = y + d[i][1];
			if (g[tx][ty] != -1 && g[tx][ty] != 0)
			{
				if (dis[(tx - 1)*n + ty] < dis[(x - 1)*n + y] + g[tx][ty])
				{
					dis[(tx - 1)*n + ty] = dis[(x - 1) * n + y] + g[tx][ty];
					ans = mymax(ans, dis[(tx - 1) * n + ty]);
					q.push(make_pair(make_pair(tx, ty), u.second + 1));
				}
			}
		}
	}
	return ans;
}

int main()
{
	//freopen("corner.in","r",stdin);freopen("corner.out","w",stdout);
	read(m);
	read(n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			read(g[i][j]);
			if (g[i][j] == 0)
			{
				sx = i;
				sy = j;
			}
		}
	printf("%lld\n", BFS());
	return 0;
}
