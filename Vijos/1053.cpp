#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAX1 = 1010;
const long INF = 0x7f7f7f;

int g[MAX1][MAX1] = {INF};
bool mark[MAX1] = {false};
int dist[MAX1] = {INF};
bool arrived[MAX1] = {false};
int num[MAX1];
int n, m, s, a, b, v, i;
queue<int> q;

bool spfa(int s)
{
	int i;
	memset(dist, INF, sizeof(dist));
	memset(num, 0, sizeof(num));
	memset(mark, false, sizeof(mark));
	while (!q.empty()) q.pop();
	q.push(s);
	num[s]++;
	mark[s] = true;
	dist[s] = 0;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		mark[t] = false;
		if (dist[s] < 0) return true;
		for (i = 1; i <= n; i++)
		{
			if (arrived[i]) continue;
			long u = g[t][i];
			if (u != INF && dist[i] > dist[t] + u)
			{
				dist[i] = dist[t] + u;
				if (!mark[i])
				{
					q.push(i);
					mark[i] = true;
					num[i]++;
					if (num[i] > n) return true;
				}
			}
		}
	}
	for (i = 1; i <= n; i++)  arrived[i] = arrived[i] || num[i];
	return false;
}

bool work()
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (!arrived[i])
			if (spfa(i))
				return true;
	}
	return false;
}

void out()
{
	if (work())
	{
		cout << "-1";
		return;
	}
	else
	{
		memset(arrived, false, sizeof(arrived));
		spfa(s);
		for (int i = 1; i <= n; i++)
		{
			if (dist[i] >= INF) printf("NoPath\n");
			else printf("%d\n", dist[i]);
		}
		return ;
	}
}
int main()
{
	memset(g, INF, sizeof(g));
	cin >> n >> m >> s;
	for (i = 1; i <= m; i++)
	{
		cin >> a >> b >> v;
		if (g[a][b] > v)
			g[a][b] = v;
	}
	out();
	return 0;
}
