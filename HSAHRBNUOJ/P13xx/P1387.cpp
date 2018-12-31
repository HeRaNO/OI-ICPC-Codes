#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath>
#define N 105
#define M 10005
#define INF 99999999.0
using namespace std;

struct point
{
	int x;
	int y;
};

int n, m;
int i, p, q, s, t;
point a[N];
int head[N], nex[M], to[M], cnt = 0;
double wei[M];

double figure(int x1, int y1, int x2, int y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double spfa(int src, int goal)
{
	queue<int> q;
	while (!q.empty()) q.pop();
	q.push(src);
	bool vis[N];
	double dist[N];
	memset(vis, false, sizeof(vis));
	fill(dist, dist + N, INF);
	vis[src] = true;
	dist[src] = 0.00;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		int i = head[u];
		for (int i = head[u]; i != -1; i = nex[i])
		{
			int v = to[i];
			if (v == 0) continue;
			if (dist[v] > dist[u] + wei[i])
			{
				dist[v] = dist[u] + wei[i];
				if (!vis[v])
				{
					q.push(v);
					vis[v] = true;
				}
			}
		}
		vis[u] = false;
	}
	return dist[goal];
}

void add(int u, int v, double w)
{
	nex[cnt] = head[u];
	to[cnt] = v;
	wei[cnt] = w;
	head[u] = cnt++;
}

int main()
{
	//freopen("a.txt","r",stdin);
	fill(head, head + N, -1);
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d %d", &a[i].x, &a[i].y);
	scanf("%d", &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &p, &q);
		add(p, q, figure(a[p].x, a[p].y, a[q].x, a[q].y));
		add(q, p, figure(a[p].x, a[p].y, a[q].x, a[q].y));
	}
	scanf("%d %d", &s, &t);
	printf("%.2lf", spfa(s, t));
	return 0;
}
