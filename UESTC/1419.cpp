#include <cstdio>
#include <numeric>
#include <algorithm>
#include <cassert>
#define MAXN 3005

int w[MAXN][MAXN], dis[MAXN];
bool vis[MAXN];

int Prim(int n)
{
	int res = 0;
	for (int i = 0; i <= n; i++)
		dis[i] = 1'000'000'000;
	dis[1] = 0;
	for (int _ = 1; _ <= n; _++)
	{
		int cur = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[i] && dis[i] < dis[cur])
				cur = i;
		assert(cur != 0);
		vis[cur] = true; res += dis[cur];
		for (int i = 1; i <= n; i++)
			dis[i] = std::min(dis[i], w[cur][i]);
	}
	return res;
}

int main()
{
	int n, t;
	scanf("%d %d", &n, &t);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			w[i][j] = -(std::gcd(i, j) & t);
	printf("%d\n", -Prim(n));
	return 0;
}