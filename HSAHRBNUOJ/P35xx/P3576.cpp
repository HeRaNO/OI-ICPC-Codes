#include <cstdio>
#include <cstring>
#define MAXN 200010
#define MAXM 400010
#define YES puts("Yes");
#define NO puts("No");
using namespace std;

struct link
{
	int to;
	int nxt;
};

link e[MAXM];
int edge_num[MAXN], cnt, top;
int dep[MAXN];
bool odd;
int n, m, u, v, T;

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

void dfs(int x, int c)
{
	dep[x] = c;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
	{
		if (dep[e[i].to] == -1) dfs(e[i].to, 3 - c);
		else if (dep[e[i].to] == dep[x]) odd = true;
	}
	return ;
}

int main()
{
	memset(edge_num, -1, sizeof edge_num);
	memset(dep, -1, sizeof dep);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		add(u, v);
	}
	dfs(1, 1);
	scanf("%d", &T);
	if (odd)
	{
		while (T--) YES return 0;
	}
	while (T--)
	{
		scanf("%d %d", &u, &v);
		if (dep[u] == dep[v]) YES
			else NO
			}
	return 0;
}
