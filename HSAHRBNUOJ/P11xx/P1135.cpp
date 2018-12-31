#include <cstdio>
#include <cstring>
using namespace std;

unsigned long long sum = 0;
int n;
bool column[1000], left_diagonal[1000], right_diagonal[1000];

void dfs(int dep)
{
	int i;
	if (dep == n + 1)
	{
		sum++;
		return ;
	}
	for (i = 1; i <= n; i++)
	{
		if ((column[i]) && (right_diagonal[i + dep]) && (left_diagonal[dep - i + n + 1]))
		{
			column[i] = false;
			right_diagonal[i + dep] = false;
			left_diagonal[dep - i + n + 1] = false;
			dfs(dep + 1);
			column[i] = true;
			right_diagonal[i + dep] = true;
			left_diagonal[dep - i + n + 1] = true;
		}
	}
}

int main()
{
	memset(column, true, sizeof(column));
	memset(left_diagonal, true, sizeof(left_diagonal));
	memset(right_diagonal, true, sizeof(right_diagonal));
	scanf("%d", &n);
	dfs(1);
	printf("%llu\n", sum);
	return 0;
}
