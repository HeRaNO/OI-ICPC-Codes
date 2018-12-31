#include <queue>
#include <cstdio>
#include <climits>
#include <cstring>
#define MAXN 55
#define MAXM 10000
using namespace std;

struct link
{
	int to;
	int nxt;
	bool phone;
};

link e[MAXM];
int n, m, k, T, cnt, ans1, ans2;
int p[MAXN], phone[MAXN][2];
int edge_num[MAXN];
int dis[MAXN][2 * MAXN][2];
bool vis[MAXN];
queue <int> q;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

void add(int u, int v, bool tel)
{
	e[cnt] = (link)
	{
		v, edge_num[u], tel
	};
	edge_num[u] = cnt++;
}

void spfa()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= 2 * m; j++)
		{
			dis[i][j][0] = INT_MAX;
			dis[i][j][1] = 0;
		}
	memset(vis, false, sizeof(vis));
	dis[0][0][0] = 0;
	vis[0] = true;
	q.push(0);
	while (!q.empty())
	{
		int u = q.front();
		vis[u] = false;
		q.pop();
		for (int i = edge_num[u]; ~i; i = e[i].nxt)
		{
			if (e[i].phone)
			{
				for (int j = 0; j <= 2 * m; j++)
				{
					if (dis[u][j][0] == INT_MAX) continue;
					else if (dis[e[i].to][j + 1][0] > dis[u][j][0] + j + k)
					{
						dis[e[i].to][j + 1][0] = dis[u][j][0] + j + k;
						dis[e[i].to][j + 1][1] = dis[u][j][1] + 1;
						if (!vis[e[i].to])
						{
							vis[e[i].to] = true;
							q.push(e[i].to);
						}
					}
					else if (dis[e[i].to][j + 1][0] == dis[u][j][0] && dis[e[i].to][j + 1][1] > dis[u][j][1] + 1)
						dis[e[i].to][j + 1][1] = dis[u][j][1] + 1;
				}
			}
			else
			{
				for (int j = 0; j <= 2 * m; j++)
				{
					if (dis[u][j][0] == INT_MAX) continue;
					else if (dis[e[i].to][j][0] > dis[u][j][0] + p[e[i].to])
					{
						dis[e[i].to][j][0] = dis[u][j][0] + p[e[i].to];
						dis[e[i].to][j][1] = dis[u][j][1] + 1;
						if (!vis[e[i].to])
						{
							vis[e[i].to] = true;
							q.push(e[i].to);
						}
					}
					else if (dis[e[i].to][j][0] == dis[u][j][0] && dis[e[i].to][j][1] > dis[u][j][1] + 1)
						dis[e[i].to][j][1] = dis[u][j][1] + 1;
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		memset(edge_num, -1, sizeof(edge_num));
		cnt = 0;
		scanf("%d", &n);
		ans1 = INT_MAX;
		for (int i = 0; i < n; i++) scanf("%d", &p[i]);
		for (int i = 0; i < n; i++)
		{
			if (p[i] == -1) continue;
			if (i && p[i - 1] != -1) add(i, i - 1, false);
			if (i + 1 < n && p[i + 1] != -1) add(i, i + 1, false);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) scanf("%d", &phone[i][0]);
		scanf("%d", &m);
		for (int i = 0; i < m; i++) scanf("%d", &phone[i][1]);
		for (int i = 0; i < m; i++)
			if (p[phone[i][1]] != -1) add(phone[i][0], phone[i][1], true);
		scanf("%d", &k);
		spfa();
		for (int i = 0; i <= 2 * m; i++)
		{
			if (dis[n - 1][i][0] == INT_MAX) continue;
			else if (dis[n - 1][i][0] < ans1)
			{
				ans1 = dis[n - 1][i][0];
				ans2 = dis[n - 1][i][1];
			}
			else if (dis[n - 1][i][0] == ans1) ans2 = mymin(ans2, dis[n - 1][i][1]);
		}
		if (ans1 == INT_MAX) printf("-1  -1\n");
		else printf("%d %d \n", ans1, ans2);
	}
	return 0;
}
