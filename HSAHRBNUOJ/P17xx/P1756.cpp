#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 1000010
using namespace std;

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int n, m, W, cnt;
int head[MAXN], dis[MAXN];
bool vis[MAXN];
queue <int> q;

struct data
{
	int to, next, v;
} e[2 * MAXN];

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int mymax(int a, int b)
{
	return a > b ? a : b;
}

void ins(int u, int v, int w)
{
	e[++cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt;
	e[cnt].v = w;
}

bool spfa()
{
	for (int i = 0; i < MAXN; i++) dis[i] = INT_MAX;
	q.push(1);
	vis[1] = true;
	dis[1] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; i; i = e[i].next)
		{
			if (dis[e[i].to] > dis[u] + e[i].v)
			{
				dis[e[i].to] = dis[u] + e[i].v;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
		}
	}
	if (dis[n] < 0) return false;
	else return true;
}

int main()
{
	//freopen("jogging.in","r",stdin);freopen("jogging.out","w",stdout);
	cnt = 0;
	memset(head, 0, sizeof(head));
	memset(vis, false, sizeof(vis));
	n = read(), m = read(), W = read();
	int u, v, w;
	for (int i = 1; i <= m; i++)
	{
		u = read(), v = read(), w = read();
		ins(mymin(u, v), mymax(u, v), w);
	}
	for (int i = 1; i <= W; i++)
	{
		u = read(), v = read(), w = read();
		ins(mymin(u, v), mymax(u, v), -w);
	}
	if (spfa())
	{
		printf("%d\n", dis[n]);
		printf("NO\n");
	}
	else
	{
		printf("%d\n", dis[n]);
		printf("YES\n");
	}
	return 0;
}
