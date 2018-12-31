#include <cstdio>
#define MAXN 21

struct tree
{
	int x, lc, rc;
	tree()
	{
		lc = rc = -1;
	}
};

tree e[MAXN];
int n, u, v;
bool first = true;

inline void dfs(int x)
{
	if (~e[x].lc) dfs(e[x].lc);
	if (first)
	{
		first = false;
		printf("%d", x);
	}
	else printf(" %d", x);
	if (~e[x].rc) dfs(e[x].rc);
	return ;
}

int main()
{
	scanf("%d %d", &n, &u);
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d", &u, &v);
		if (!~e[u].lc) e[u].lc = v;
		else e[u].rc = v;
	}
	dfs(1);
	putchar('\n');
	return 0;
}
