#include <cstdio>
#include <algorithm>
#define MAXN 210
using namespace std;

int T;
int n, m;
int son_num[MAXN], tmp, x;
int tree[MAXN][MAXN];

bool cmp(int a, int b)
{
	return a > b;
}

int dfs(int node)
{
	if (!node) return 1;
	int need[MAXN];
	for (int i = 1; i <= son_num[node]; i++) need[i] = dfs(tree[node][i]);
	sort(need + 1, need + son_num[node] + 1, cmp);
	int ne = 0, left = 0;
	for (int i = 1; i <= son_num[node]; i++)
	{
		if (left < need[i])
		{
			ne += need[i] - left;
			left = need[i] - 1;
		}
		else left -= 1;
	}
	return ne;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", &tmp, &son_num[i]);
			for (int j = 1; j <= son_num[i]; j++)
				scanf("%d", &tree[tmp][j]);
		}
		printf("%d\n", dfs(1) + 1);
	}
	return 0;
}
