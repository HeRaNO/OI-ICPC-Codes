#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 30010
using namespace std;

int n, m, b, l, S, T;
int siz[MAXN];
vector <int> p[MAXN];
int dis[MAXN];
bool vis[MAXN], have[MAXN][210];
queue <int> q;

inline int SPFA()
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
		for (int i = siz[u] - 1; ~i; i--)
		{
			for (int j = 1; u + j * p[u][i] < n; j++)
			{
				if (dis[u + j * p[u][i]] > dis[u] + j)
				{
					dis[u + j * p[u][i]] = dis[u] + j;
					if (!vis[u + j * p[u][i]])
					{
						vis[u + j * p[u][i]] = true;
						q.push(u + j * p[u][i]);
					}
				}
				if (p[u][i] <= 200 && have[u + j * p[u][i]][p[u][i]]) break;
			}
			for (int j = 1; u - j * p[u][i] >= 0; j++)
			{
				if (dis[u - j * p[u][i]] > dis[u] + j)
				{
					dis[u - j * p[u][i]] = dis[u] + j;
					if (!vis[u - j * p[u][i]])
					{
						vis[u - j * p[u][i]] = true;
						q.push(u - j * p[u][i]);
					}
				}
				if (p[u][i] <= 200 && have[u - j * p[u][i]][p[u][i]]) break;
			}
		}
	}
	return dis[T] == 0x7f7f7f7f ? -1 : dis[T];
}

inline int read()
{
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int main()
{
	n = read();
	m = read();
	for (int i = 0; i < m; i++)
	{
		b = read();
		l = read();
		if (!i) S = b;
		if (!(i - 1)) T = b;
		p[b].push_back(l);
		if (l <= 200) have[b][l] = true;
	}
	for (int i = 0; i < n; i++)
	{
		sort(p[i].begin(), p[i].end());
		siz[i] = unique(p[i].begin(), p[i].end()) - p[i].begin();
	}
	printf("%d\n", SPFA());
	return 0;
}
