#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXN 50110
#define MAXM 500110
using namespace std;

struct link
{
	int to;
	int nxt;
};

link e[MAXM];
int edge_num[MAXN];
int n, m, cnt;
int u, v;
int color[MAXN];
int s1[MAXN], s2[MAXN];

void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = cnt++;
	e[cnt] = (link)
	{
		u, edge_num[v]
	};
	edge_num[v] = cnt++;
}

void stop()
{
	printf("IMPOSSIBLE\n");
	exit(0);
}

void binary_color(int dep, int c)
{
	color[dep] = c;
	for (int i = edge_num[dep]; ~i; i = e[i].nxt)
	{
		if (color[e[i].to] == c) stop();
		if (!color[e[i].to]) binary_color(e[i].to, 3 - c);
	}
}

int main()
{
	memset(edge_num, -1, sizeof(edge_num));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		add(u, v);
	}
	for (int i = 1; i <= n; i++)
		if (!color[i]) binary_color(i, 1);
	for (int i = 1; i <= n; i++)
	{
		if (color[i] == 1) s1[++s1[0]] = i;
		else s2[++s2[0]] = i;
	}
	for (int i = 1; i < s1[0]; i++) printf("%d ", s1[i]);
	printf("%d\n", s1[s1[0]]);
	for (int i = 1; i < s2[0]; i++) printf("%d ", s2[i]);
	printf("%d\n", s2[s2[0]]);
	return 0;
}
