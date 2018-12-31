#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 101
#define MAXK 11
using namespace std;

const int d[4][2] =
{
	{1, 0}, {0, 1},
	{-1, 0}, {0, -1}
};

struct link
{
	int to, val, nxt;
};

link e[MAXN * MAXN * MAXK * 5];
int head[MAXN * MAXN * MAXK], cnt;
int n, k, a, b, c, x, S, T, r;
int dis[MAXN * MAXN * MAXK];
bool vis[MAXN * MAXN * MAXK];
queue <int> q;

inline int GetHash(int x, int y, int o)
{
	return (x - 1) * n + y + o * n * n;
}

inline int mymin(int a, int b)
{
	return a < b ? a : b;
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
	vis[S] = true;
	dis[S] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; i; i = e[i].nxt)
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
	int ans = ~(1 << 31);
	for (int i = 0; i <= k; i++) ans = mymin(ans, dis[GetHash(n, n, i)]);
	return ans;
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
	//freopen("trav.in","r",stdin);freopen("trav.out","w",stdout);
	read(n);
	read(k);
	read(a);
	read(b);
	read(c);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			read(x);
			for (int t = 0; t <= k; t++)
			{
				r = x ? a : a + c;
				if (t < k) add(GetHash(i, j, t), GetHash(i, j, k), r);
				if ((!x && t > 0) || t == k)
				{
					for (int s = 0; s < 4; s++)
					{
						int x = i + d[s][0], y = j + d[s][1];
						r = s < 2 ? 0 : b;
						if (x >= 1 && x <= n && y >= 1 && y <= n)
							add(GetHash(i, j, t), GetHash(x, y, t - 1), r);
					}
				}
			}
		}
	printf("%d\n", SPFA(GetHash(1, 1, k)));
	return 0;
}