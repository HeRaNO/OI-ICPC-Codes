#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 16
#define MAXP 11
using namespace std;

const int d[4][2] =
{
	{1, 0}, {-1, 0},
	{0, 1}, {0, -1}
};

struct link
{
	int to, val, nxt;
};

link e[MAXN * MAXN * (1 << MAXP - 1) << 1];
int head[MAXN * MAXN * (1 << MAXP - 1)], cnt;
int n, m, p, k, s, _2pow[MAXP];
int dis[MAXN * MAXN * (1 << MAXP - 1)];
bool vis[MAXN * MAXN * (1 << MAXP - 1)];
int mp[MAXN][MAXN][MAXN][MAXN];
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline int GetHash(int x, int y, int version)
{
	return (x - 1) * m + y + version * n * m;
}

inline void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, head[u]
	};
	head[u] = cnt++;
}

inline int SPFA(int S)
{
	memset(dis, 0x7f, sizeof dis);
	q.push(S);
	dis[S] = 0;
	vis[S] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; ~i; i = e[i].nxt)
			if (dis[e[i].to] > dis[u] + e[i].val)
			{
				dis[e[i].to] = dis[u] + e[i].val;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
	}
	int res = ~(1 << 31);
	for (int i = 0; i < _2pow[p]; i++) res = mymin(res, dis[GetHash(n, m, i)]);
	return res == 0x7f7f7f7f ? -1 : res;
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
	//freopen("rescue.in","r",stdin);freopen("rescue.out","w",stdout);
	memset(head, -1, sizeof head);
	int x1, y1, x2, y2, z;
	memset(mp, -1, sizeof mp);
	_2pow[0] = 1;
	for (int i = 1; i <= 10; i++) _2pow[i] = _2pow[i - 1] << 1;
	read(n);
	read(m);
	read(p);
	read(k);
	for (int i = 1; i <= k; i++)
	{
		read(x1);
		read(y1);
		read(x2);
		read(y2);
		read(z);
		z = z ? z - 1 : -2;
		mp[x1][y1][x2][y2] = mp[x2][y2][x1][y1] = z;
	}
	read(s);
	for (int i = 1; i <= s; i++)
	{
		read(x1);
		read(y1);
		read(z);
		z--;
		for (int j = 0; j < _2pow[p]; j++)
			if (!(j & (1 << z)))
				add(GetHash(x1, y1, j), GetHash(x1, y1, j | (1 << z)), 0);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 0; k < 4; k++)
			{
				int x = i + d[k][0], y = j + d[k][1];
				if (x <= 0 || x > n || y <= 0 || y > m) continue;
				if (!~mp[i][j][x][y])
				{
					for (int t = 0; t < _2pow[p]; t++)
						add(GetHash(i, j, t), GetHash(x, y, t), 1);
				}
				if (mp[i][j][x][y] >= 0)
				{
					for (int t = 0; t < _2pow[p]; t++)
						if (t & (1 << mp[i][j][x][y]))
							add(GetHash(i, j, t), GetHash(x, y, t), 1);
				}
			}
	printf("%d\n", SPFA(GetHash(1, 1, 0)));
	return 0;
}
