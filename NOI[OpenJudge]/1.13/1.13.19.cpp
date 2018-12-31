//Code By HeRaNO
#include <cstdio>
#include <algorithm>
#define MAXN 10010
#define LL_MAX 9223372036854775807
using namespace std;

int n, pos;
int d[MAXN], num[MAXN];
long long dis[MAXN];
long long ans = LL_MAX, sum, dis1, dis2;

long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &num[i], &d[i]);
	for (int i = 1; i <= n; i++) dis[i] = dis[i - 1] + d[i - 1];
	for (int i = 1; i <= n; i++)
	{
		sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			int ii = i, jj = j;
			if (ii > jj) swap(ii, jj);
			sum += mymin(dis[jj] - dis[ii], dis[ii] - dis[jj] + dis[n] + d[n]) * num[j];
		}
		if (ans > sum) ans = sum, pos = i - 1;
	}
	printf("%d,%lld", pos, ans);
	return 0;
}
