#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 1010
using namespace std;

struct point
{
	int x;
	int y;
};

bool a[MAXN][MAXN];
int n, m;
int qx, qy, ans[MAXN][MAXN];
bool vis[MAXN][MAXN];
queue <point> q;
queue <point> cur;
char s[MAXN];

void BFS(int x, int y)
{
	vis[x][y] = true;
	int res = 1;
	q.push((point)
	{
		x, y
	});
	cur.push((point)
	{
		x, y
	});
	while (!q.empty())
	{
		point u = q.front();
		q.pop();
		if (u.x + 1 <= n && (a[u.x][u.y]^a[u.x + 1][u.y]) && (!vis[u.x + 1][u.y]))
		{
			res++;
			vis[u.x + 1][u.y] = true;
			q.push((point)
			{
				u.x + 1, u.y
			});
			cur.push((point)
			{
				u.x + 1, u.y
			});
		}
		if (u.x - 1 >= 1 && (a[u.x][u.y]^a[u.x - 1][u.y]) && (!vis[u.x - 1][u.y]))
		{
			res++;
			vis[u.x - 1][u.y] = true;
			q.push((point)
			{
				u.x - 1, u.y
			});
			cur.push((point)
			{
				u.x - 1, u.y
			});
		}
		if (u.y + 1 <= n && (a[u.x][u.y]^a[u.x][u.y + 1]) && (!vis[u.x][u.y + 1]))
		{
			res++;
			vis[u.x][u.y + 1] = true;
			q.push((point)
			{
				u.x, u.y + 1
			});
			cur.push((point)
			{
				u.x, u.y + 1
			});
		}
		if (u.y - 1 >= 1 && (a[u.x][u.y]^a[u.x][u.y - 1]) && (!vis[u.x][u.y - 1]))
		{
			res++;
			vis[u.x][u.y - 1] = true;
			q.push((point)
			{
				u.x, u.y - 1
			});
			cur.push((point)
			{
				u.x, u.y - 1
			});
		}
	}
	while (!cur.empty())
	{
		point u = cur.front();
		cur.pop();
		ans[u.x][u.y] = res;
	}
	return ;
}

int main()
{
	//freopen("maze01.in","r",stdin);freopen("maze01.out","w",stdout);
	memset(vis, false, sizeof(vis));
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		for (int j = 0; j < n; j++)
			a[i][j + 1] = (s[j] - '0');
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (!vis[i][j]) BFS(i, j);
	while (m--)
	{
		scanf("%d %d", &qx, &qy);
		printf("%d\n", ans[qx][qy]);
	}
	return 0;
}
