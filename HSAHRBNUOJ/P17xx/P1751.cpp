#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#define MAXN 1010
using namespace std;

struct bus
{
	int dis;//最短距离
	int time;//最少转车次数
};

bus a[MAXN];
int in[MAXN];
int dist[MAXN][MAXN];
int graph[MAXN][MAXN];
int cnt, x, len;
bool vis[MAXN];
int n, m, flag;
string tmp;
queue <int> q;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

void read(int flag, int h)
{
	cnt = x = 0;
	memset(in, 0, sizeof in);
	getline(cin, tmp);
	len = tmp.length();
	for (int p = 0; p < len; p++)
	{
		if (tmp[p] == ' ')
		{
			in[++cnt] = x;
			x = 0;
		}
		else x = x * 10 + (tmp[p] - '0');
	}
	if (x) in[++cnt] = x;
	if (flag == 2)
	{
		n = in[1];
		m = in[2];
	}
	else if (flag == 1)
	{
		for (int i = 1; i <= n; i++) dist[h][i] = in[i];
	}
	else
	{
		for (int j = 1; j <= cnt; j++)
		{
			int bestmin = 0;
			for (int k = j + 1; k <= cnt; k++)
			{
				bestmin += dist[in[k - 1]][in[k]];
				graph[in[j]][in[k]] = mymin(graph[in[j]][in[k]], bestmin);
				graph[in[k]][in[j]] = mymin(graph[in[k]][in[j]], bestmin);
			}
		}
		//处理一条线路上一个站到另一个站最短距离
	}
	return ;
}

void spfa(int src, int goal)
{
	q.push(src);
	memset(vis, false, sizeof(vis));
	vis[src] = true;
	a[src].dis = 0;
	a[src].time = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = 1; i <= n; i++)
		{
			if (a[i].time > a[u].time + 1 && a[i].dis > a[u].dis + graph[u][i]) //优先松弛转车次数
			{
				a[i].time = a[u].time + 1;
				a[i].dis = a[u].dis + graph[u][i];
				if (!vis[i])
				{
					q.push(i);
					vis[i] = true;
				}
			}
			else if (a[i].time == a[u].time + 1 && a[i].dis > a[u].dis + graph[u][i]) //如果无法松弛，松弛距离
			{
				a[i].dis = a[u].dis + graph[u][i];
				if (!vis[i])
				{
					q.push(i);
					vis[i] = true;
				}
			}
		}
	}
}

int main()
{
	//freopen("bus.in","r",stdin);freopen("bus.out","w",stdout);
	memset(graph, 0x7f, sizeof graph);
	read(2, 0);
	for (int i = 1; i <= n; i++) read(1, i);
	while (m--) read(0, 0);
	memset(a, 0x7f, sizeof a);
	spfa(1, n);
	printf("%d %d\n", a[n].time, a[n].dis);
	return 0;
}
