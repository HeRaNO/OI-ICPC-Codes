#include <cstdio>
#include <cstring>
#define MAXN 310
using namespace std;

struct tree
{
	int f[MAXN], child[MAXN];
} node[MAXN];
int m, n, tmp[MAXN], a, b;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void Merge(int x, int y)
{
	for (int i = 1; i <= n; i++)
	{
		tmp[i] = node[x].f[i];
		for (int j = (!x ? 0 : 1); j <= i; j++)
			tmp[i] = mymax(tmp[i], node[x].f[j] + node[y].f[i - j]);
	}
	for (int i = 1; i <= n; i++) node[x].f[i] = tmp[i];
}

void dfs(int root)
{
	for (int i = 1; i <= node[root].child[0]; i++)
	{
		dfs(node[root].child[i]);
		Merge(root, node[root].child[i]);
	}
}

int main()
{
	memset(node, 0, sizeof(node));
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		node[a].child[++node[a].child[0]] = i;
		for (int j = 1; j <= n; j++) node[i].f[j] = b;
	}
	dfs(0);
	printf("%d", node[0].f[n]);
	return 0;
}