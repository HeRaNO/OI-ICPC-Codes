//Code By HeRaNO
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10
using namespace std;

int m, n;

int main()
{
	scanf("%d %d", &m, &n);
	int **bacteria = new int *[10];
	for (int i = 0; i <= 9; i++)
		bacteria[i] = new int[10];
	int **bacteria_pre = new int *[10];
	for (int i = 0; i <= 9; i++)
		bacteria_pre[i] = new int[10];
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			bacteria[i][j] = bacteria_pre[i][j] = 0;
	bacteria[5][5] = m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 9; j++)
			for (int k = 1; k <= 9; k++)
			{
				if (bacteria[j][k])
				{
					bacteria_pre[j][k] += bacteria[j][k] * 2;
					bacteria_pre[j - 1][k] += bacteria[j][k];
					bacteria_pre[j + 1][k] += bacteria[j][k];
					bacteria_pre[j][k - 1] += bacteria[j][k];
					bacteria_pre[j][k + 1] += bacteria[j][k];
					bacteria_pre[j - 1][k - 1] += bacteria[j][k];
					bacteria_pre[j - 1][k + 1] += bacteria[j][k];
					bacteria_pre[j + 1][k - 1] += bacteria[j][k];
					bacteria_pre[j + 1][k + 1] += bacteria[j][k];
				}
			}
		swap(bacteria, bacteria_pre);
		for (int i = 0; i <= 9; i++)
			for (int j = 0; j <= 9; j++)
				bacteria_pre[i][j] = 0;
	}
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
			printf("%d ", bacteria[i][j]);
		printf("\n");
	}
	return 0;
}
