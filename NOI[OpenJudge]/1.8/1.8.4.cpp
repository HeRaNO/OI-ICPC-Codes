//Code By HeRaNO
#include <cstdio>
#define MAXN 101
using namespace std;

int a[MAXN][MAXN];
int n;

bool check()
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (a[i][j]) sum++;
		if (sum % 2) return false;
	}
	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i <= n; i++)
			if (a[i][j]) sum++;
		if (sum % 2) return false;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	if (check())
	{
		printf("OK\n");
		return 0;
	}
	else
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (a[i][j]) a[i][j] = 0;
				else a[i][j] = 1;
				if (check())
				{
					printf("%d %d\n", i, j);
					return 0;
				}
				if (a[i][j]) a[i][j] = 0;
				else a[i][j] = 1;
			}
	}
	printf("Corrupt\n");
	return 0;
}
