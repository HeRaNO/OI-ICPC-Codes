#include <cstdio>
#define MAXN 510
using namespace std;

int n, V;
int v[MAXN];
bool dp[MAXN][MAXN];
int ans[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	dp[0][0] = true;
	scanf("%d %d", &n, &V);
	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = mymax(V - v[i], 0); ~j; j--)
			for (int k = mymax(V - v[i] - j, 0); k >= 0; k--)
				if (dp[j][k]) dp[j][k + v[i]] = dp[j + v[i]][k] = true;
	}
	while (!ans[0])
	{
		for (int i = 0; i <= V; i++)
			if (dp[i][V - i])
				ans[++ans[0]] = i;
		V--;
	}
	printf("%d\n", ans[0]);
	for (int i = 1; i <= ans[0]; i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
