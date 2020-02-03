#include <cstdio>
#include <queue>
#include <cstring>
using std::queue;
#define N 1005
#define M 1000005

int n, m;
int hour, min, second;
int head[N], next[M], to[M], wei[M], cnt = 0;

int spfa(int src, int goal)
{
	queue<int> q;
	q.push(src);
	int vis[N], dist[N];
	memset(vis, 0, sizeof(vis));
	memset(dist, 127, sizeof(dist));
	vis[src] = 1;
	dist[src] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i != -1; i = next[i])
		{
			int v = to[i];
			if (v == 0) continue;
			if (dist[v] > dist[u] + wei[i])
			{
				dist[v] = dist[u] + wei[i];
				if (!vis[v])
				{
					q.push(v);
					vis[v] = 1;
				}
			}
		}
		vis[u] = 0;
	}
	return dist[goal];
}

void add(int u, int v, int w)
{
	next[cnt] = head[u];
	to[cnt] = v;
	wei[cnt] = w;
	head[u] = cnt++;
}

int main()
{
	scanf("%d:%d", &hour, &min);
	second = 0;
	scanf("%d%d", &n, &m);
	int a, b, c;
	memset(head, -1, sizeof(head));
	while (m--)
	{
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
		add(b, a, c);
	}
	second = 0;
	min += spfa(1, n);
	char ch[10];
	scanf("%d%s", &m, ch);
	switch (ch[0])
	{
	case 'm':
		min += m;
		break;
	case 's':
		second += m;
		break;
	case 'h':
		hour += m;
		break;
	}
	min += second / 60;
	second %= 60;
	hour += min / 60;
	min %= 60;
	if (hour > 24)
		printf("Sad");
	else
		printf("%d:%02d", hour, min);
	return 0;
}
