#include <cstdio>
using namespace std;

const int MAXN = 1502;
int tree[MAXN][MAXN], N, f[MAXN][2], root;
bool used[MAXN];

int mymin(int a, int b)
{
	return a < b ? a : b;
}

void DFS(int root)
{
	if (!tree[root][0])
	{
		f[root][1] = 1;
		return;
	}
	for (int i = 1; i <= tree[root][0]; i++)
	{
		DFS(tree[root][i]);
		f[root][0] += f[tree[root][i]][1];
		f[root][1] += mymin(f[tree[root][i]][1], f[tree[root][i]][0]);
	}
	f[root][1]++;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1, node; i <= N; i++)
	{
		scanf("%d", &node);
		scanf("%d", &tree[node][0]);
		for (int j = 1; j <= tree[node][0]; j++)
		{
			scanf("%d", &tree[node][j]);
			used[tree[node][j]] = 1;
		}
	}
	if (N == 1)
	{
		scanf("1");
		return 0;
	}
	for (int i = 0; 1; i++)
		if (!used[i] && tree[i][0])
		{
			root = i;
			break;
		}
	DFS(root);
	printf("%d\n", mymin(f[root][0], f[root][1]));
	return 0;
}
