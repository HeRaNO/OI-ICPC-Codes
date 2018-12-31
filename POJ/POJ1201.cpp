#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 150000
using namespace std;

int n;
int u, v, w;
int left = INT_MAX, right = -INT_MAX;
int head[MAXN], nex[MAXN], to[MAXN], cnt = 0;
int wei[MAXN];
bool vis[MAXN];
int dist[MAXN];
int num[MAXN];
queue <int> q;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int spfa(int src, int goal)
{
	q.push(src);
	memset(vis, false, sizeof(vis));
	vis[src] = true;
	dist[src] = 0;
	num[src]++;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; i != -1; i = nex[i])
		{
			int v = to[i];
			if (v == 0) continue;
			if (dist[v] < dist[u] + wei[i])
			{
				dist[v] = dist[u] + wei[i];
				if (!vis[v])
				{
					q.push(v);
					vis[v] = true;
					num[v]++;
					if (num[v] >= n) return -1;
				}
			}
		}
	}
	return dist[goal];
}

void add(int u, int v, int w)
{
	nex[cnt] = head[u];
	to[cnt] = v;
	wei[cnt] = w;
	head[u] = cnt++;
}

int main()
{
	memset(head, -1, sizeof(head));
	for (int i = 0; i < MAXN; i++)
		dist[i] = -INT_MAX;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		add(u, v + 1, w);
		left = mymin(left, u);
		right = mymax(right, v + 1);
	}
	for (int i = left; i < right; i++)
	{
		add(i, i + 1, 0);
		add(i + 1, i, -1);
	}
	printf("%d\n", spfa(left, right));
	return 0;
}
