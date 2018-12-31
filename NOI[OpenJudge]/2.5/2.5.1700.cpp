//Code By HeRaNO
#include <cstdio>
#include <cstring>
using namespace std;

int sum;
int n;
bool column[1000], left_diagonal[1000], right_diagonal[1000];
bool put[9][9];

void dfs(int dep)
{
	if (dep == n + 1)
	{
		sum++;
		printf("No. %d\n", sum);
		for (int i = 1; i <= 8; i++)
		{
			for (int j = 1; j <= 8; j++)
				printf("%d ", put[j][i]);
			printf("\n");
		}
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if ((column[i]) && (right_diagonal[i + dep]) && (left_diagonal[i - dep + 7]))
		{
			column[i] = false;
			right_diagonal[i + dep] = false;
			left_diagonal[i - dep + 7] = false;
			put[dep][i] = true;
			dfs(dep + 1);
			column[i] = true;
			right_diagonal[i + dep] = true;
			left_diagonal[i - dep + 7] = true;
			put[dep][i] = false;
		}
	}
}

int main()
{
	memset(column, true, sizeof(column));
	memset(left_diagonal, true, sizeof(left_diagonal));
	memset(right_diagonal, true, sizeof(right_diagonal));
	memset(put, false, sizeof(put));
	n = 8;
	dfs(1);
	return 0;
}
