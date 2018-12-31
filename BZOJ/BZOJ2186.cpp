#include <cstdio>
#define MAXN 10000010
using namespace std;

long long prime[700000], fac[MAXN], inv[MAXN], ans[MAXN];
bool not_prime[MAXN];
int n, m, T, MOD, tot;

inline void Linear_Shaker()
{
	int N = 1e7;
	fac[1] = inv[1] = ans[1] = 1LL;
	long long P = MOD;
	for (int i = 2; i <= N; i++)
	{
		if (i < P) inv[i] = (P - P / i) * inv[P % i] % P;
		fac[i] = fac[i - 1] * i % P;
		if (!not_prime[i]) prime[++tot] = i;
		for (int j = 1; i * prime[j] <= N; j++)
		{
			not_prime[i * prime[j]] = true;
			if (!(i % prime[j])) break;
		}
	}
	for (int i = 2; i <= N; i++)
	{
		if (!not_prime[i]) ans[i] = ans[i - 1] * (i - 1) % P * inv[i % P] % P;
		else ans[i] = ans[i - 1];
	}
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(T);
	read(MOD);
	Linear_Shaker();
	while (T--)
	{
		read(n);
		read(m);
		printf("%d\n", fac[n]*ans[m] % MOD);
	}
	return 0;
}