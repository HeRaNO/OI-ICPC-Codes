#include <iostream>
#include <cstdio>
#include <cstring>
#define M 1001
#define INF 0x7fffffff
using namespace std;

int n, m;
int a[M], f[M];
int b[M];
int maxx = 0;

int getmax(int x)
{
	for (int i = 1; i <= M; i++)
		f[i] = INF;
	f[0] = 0;
	int k;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= x; j++)
			if (i - a[j] >= 0)
				f[i] = min(f[i - a[j]] + 1, f[i]);
		if (f[i] > n)
		{
			k = i - 1;
			break;
		}
	}
	return k;
}

void dfs(int num)
{
	int now = getmax(num);
	if (num == m)
	{
		if (now > maxx)
		{
			maxx = now;
			memcpy(b, a, sizeof(a));
			return ;
		}
	}
	else
	{
		for (int i = now + 1; i >= a[num] + 1; i--)
		{
			a[num + 1] = i;
			dfs(num + 1);
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	a[1] = 1;
	dfs(1);
	for (int i = 1; i <= m; i++)
		printf("%d ", b[i]);
	printf("\nMAX=%d", maxx);
	return 0;
}