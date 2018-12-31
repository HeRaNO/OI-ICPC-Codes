#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 420
using namespace std;

int n, m;
int u, v, w;
int head[MAXN], nex[MAXN], to[MAXN], cnt = 2;
int wei[MAXN];
int dis[MAXN];
int from[MAXN];
int ans;
queue <int> q;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

void add(int u, int v, int w)
{
	nex[cnt] = head[u];
	to[cnt] = v;
	wei[cnt] = w;
	head[u] = cnt++;
}

bool edmonds_karp()
{
	memset(dis, 0, sizeof(dis));
	dis[1] = INT_MAX;
	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = head[x]; i; i = nex[i])
			if (wei[i] && !dis[to[i]])
			{
				dis[to[i]] = mymin(wei[i], dis[x]);
				from[to[i]] = i;
				q.push(to[i]);
			}
	}
	if (!dis[m]) return false;
	ans += dis[m];
	for (int i = from[m]; i; i = from[to[i ^ 1]])
		wei[i] -= dis[m], wei[i ^ 1] += dis[m];
	return true;
}

int main()
{
	while (~scanf("%d %d", &n, &m))
	{
		memset(head, 0, sizeof(head));
		cnt = 2;
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d %d", &u, &v, &w);
			add(u, v, w);
			add(v, u, 0);
		}
		while (edmonds_karp());
		printf("%d\n", ans);
	}
	return 0;
}
