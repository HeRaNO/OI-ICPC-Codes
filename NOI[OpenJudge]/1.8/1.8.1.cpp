//Code By HeRaNO
#include <cstdio>
#include <algorithm>
#define MAXN 6
using namespace std;

int a[MAXN][MAXN];
int from, to;
int order[6] = {0, 1, 2, 3, 4, 5};

int main()
{
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			scanf("%d", &a[i][j]);
	scanf("%d %d", &from, &to);
	swap(order[from], order[to]);
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
			printf("%d ", a[order[i]][j]);
		printf("\n");
	}
	return 0;
}
