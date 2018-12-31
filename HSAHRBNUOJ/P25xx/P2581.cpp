#include <queue>
#include <cstdio>
#define MAXN 51
using namespace std;

struct syndicate
{
	int x, y, dis, ele;
};

const int d[4][2] =
{
	{1, 0}, {-1, 0},
	{0, 1}, {0, -1}
};
int n, m, x;
int g[MAXN][MAXN];
int _2pow[17];
queue <syndicate> q;
bool vis[1 << 17][MAXN][MAXN];

inline int BFS()
{
	q.push((syndicate)
	{
		1, 1, 0, 0
	});
	vis[0][1][1] = true;
	while (!q.empty())
	{
		syndicate u = q.front();
		q.pop();
		if (u.x == n && u.y == n) return u.dis;
		for (int i = 0; i < 4; i++)
		{
			int tx = u.x + d[i][0], ty = u.y + d[i][1];
			if (tx <= 0 || tx > n || ty <= 0 || ty > n || vis[u.ele][tx][ty] || g[tx][ty] < 0) continue;
			if (g[tx][ty] == 0)
			{
				vis[u.ele][tx][ty] = true;
				q.push((syndicate)
				{
					tx, ty, u.dis + 1, u.ele
				});
			}
			else if (g[tx][ty] > m)
			{
				if ((u.ele & _2pow[g[tx][ty] - m]) == _2pow[g[tx][ty] - m])
				{
					vis[u.ele][tx][ty] = true;
					q.push((syndicate)
					{
						tx, ty, u.dis + 1, u.ele
					});
				}
			}
			else
			{
				int newele = u.ele | _2pow[g[tx][ty]];
				vis[u.ele][tx][ty] = vis[newele][tx][ty] = true;
				q.push((syndicate)
				{
					tx, ty, u.dis + 1, newele
				});
			}
		}
	}
}

int main()
{
	//freopen("syndicate.in","r",stdin);freopen("syndicate.out","w",stdout);
	_2pow[0] = 1;
	for (int i = 1; i <= 16; i++) _2pow[i] = _2pow[i - 1] << 1;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &x);
			if (g[i][j] != -1) g[i][j] = x;
			if (x == -2) g[i][j] = g[i - 1][j] = g[i][j - 1] = g[i + 1][j] = g[i][j + 1] = -1;
		}
	printf("%d\n", BFS());
	return 0;
}
