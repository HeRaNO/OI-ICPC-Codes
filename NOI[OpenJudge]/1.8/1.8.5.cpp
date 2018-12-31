//Code By HeRaNO
#include <cstdio>
#include <climits>
#define MAXN 6
using namespace std;

int a[MAXN][MAXN];
int cnt[MAXN][MAXN];
int big, bigpos, small, smallpos;
bool out = false;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= 5; i++)
	{
		big = 0;
		for (int j = 1; j <= 5; j++)
		{
			if (big < a[i][j])
			{
				big = a[i][j];
				bigpos = j;
			}
		}
		cnt[i][bigpos]++;
	}
	for (int i = 1; i <= 5; i++)
	{
		small = INT_MAX;
		for (int j = 1; j <= 5; j++)
		{
			if (small > a[j][i])
			{
				small = a[j][i];
				smallpos = j;
			}
		}
		cnt[smallpos][i]++;
	}
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			if (cnt[i][j] == 2)
			{
				printf("%d %d %d\n", i, j, a[i][j]);
				out = true;
				return 0;
			}
	if (!out) printf("not found\n");
	return 0;
}
