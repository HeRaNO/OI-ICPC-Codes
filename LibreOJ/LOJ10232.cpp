#include <cstdio>
#define MAXN 2010
#define MOD 100003

long long C[MAXN][MAXN], A[MAXN], ans;
int a, b, c, d, k;

int mymin(int a, int b)
{
	return a < b ? a : b;
}
long long query(int a, int b, int k)
{
	return ((C[a][k] * C[b][k] % MOD) * A[k]) % MOD;
}

int main()
{
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
	A[0] = 1LL;
	for (int i = 0; i < MAXN; i++)
	{
		C[i][0] = C[i][i] = 1LL;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
	}
	for (int i = 1; i < MAXN; i++) A[i] = (A[i - 1] * i) % MOD;
	for (int i = 0; i <= mymin(mymin(a, b), k); i++)
		ans = (ans + query(a, b, i) * query(a + c - i, d, k - i) % MOD) % MOD;
	ans %= MOD;
	printf("%lld\n", ans);
	return 0;
}