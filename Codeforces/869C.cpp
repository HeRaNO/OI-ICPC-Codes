#include <cstdio>
#define MAXN 5010
using namespace std;

const long long MOD = 998244353;
long long fac[MAXN], inv[MAXN], invfac[MAXN], ans = 1LL;
int mx, A, B, c;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void PreWork()
{
	fac[0] = fac[1] = inv[0] = inv[1] = invfac[0] = invfac[1] = 1;
	for (int i = 2; i <= mx; i++)
	{
		fac[i] = (fac[i - 1] * i) % MOD;
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
		invfac[i] = (invfac[i - 1] * inv[i]) % MOD;
	}
	return ;
}

inline long long C(int n, int m)
{
	return fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

inline long long Calculate(int a, int b)
{
	long long ans = 0LL;
	for (int i = 0; i <= a && i <= b; i++) ans = (ans + fac[i] * C(a, i) % MOD * C(b, i) % MOD) % MOD;
	return ans;
}

int main()
{
	read(A);
	read(B);
	read(c);
	mx = mymax(mymax(A, B), c);
	PreWork();
	ans = (ans * Calculate(A, B)) % MOD;
	ans = (ans * Calculate(A, c)) % MOD;
	ans = (ans * Calculate(B, c)) % MOD;
	printf("%I64d\n", ans);
	return 0;
}