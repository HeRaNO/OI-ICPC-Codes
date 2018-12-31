#include <cstdio>
#define MOD 10007
using namespace std;

int a, b, k, n, m;
long long ans;
long long triangle[1010][5000];

int main()
{
	//freopen("factor.in","r",stdin);freopen("factor.out","w",stdout);
	scanf("%d %d %d %d %d", &a, &b, &k, &n, &m);
	triangle[1][1] = 1;
	triangle[1][2] = 1;
	for (int i = 2; i <= k; i++)
		for (int j = 1; j <= i + 1; j++)
			triangle[i][j] = (triangle[i - 1][j] + triangle[i - 1][j - 1]) % MOD;
	ans = triangle[k][m + 1];
	for (int i = 1; i <= n; i++)
		ans = (ans * a) % MOD;
	for (int i = 1; i <= m; i++)
		ans = (ans * b) % MOD;
	printf("%lld\n", ans);
	return 0;
}