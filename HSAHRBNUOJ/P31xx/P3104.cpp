#include <cstdio>
#define MAXN 21
using namespace std;

bool a[MAXN][MAXN], vis[MAXN];
int n, m, x, y;
long long fac[MAXN], ans;

long long dfs(int dep, int x)
{
	if (!x) return 1LL;
	if (dep > n) return 0LL;
	long long ans = dfs(dep + 1, x);
	for (int i = 1; i <= n; i++)
		if (a[dep][i] && !vis[i])
		{
			vis[i] = true;
			ans += dfs(dep + 1, x - 1);
			vis[i] = false;
		}
	return ans;
}

int main()
{
	//freopen("arrange.in","r",stdin);freopen("arrange.out","w",stdout);
	scanf("%d%d", &n, &m);
	fac[0] = 1LL;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
	for (int i = 1; i <= m; i++) scanf("%d%d", &x, &y), a[x][y] = true;
	for (int i = 0; i <= n; i++)
		if (i & 1) ans -= fac[n - i] * dfs(1, i);
		else ans += fac[n - i] * dfs(1, i);
	printf("%lld\n", ans);
	return 0;
}