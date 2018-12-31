#include <cstdio>
#define MAXN 1000010

int n, T, l, r, c;
long long fac[MAXN], inv[MAXN], invfac[MAXN];
long long ans[MAXN], MOD;

inline long long C(int m, int n)
{
	return fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}

inline long long KSM(long long a, int b)
{
	long long res = 1LL, base = a;
	while (b)
	{
		if (b & 1) res = res * base % MOD;
		base = base * base % MOD;
		b >>= 1;
	}
	return res;
}

inline void Getans()
{
	inv[1] = 1LL;
	fac[1] = 1LL;
	invfac[0] = 1LL;
	invfac[1] = 1LL;
	for (int i = 2; i <= n; i++)
	{
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
		fac[i] = fac[i - 1] * i % MOD;
		invfac[i] = invfac[i - 1] * inv[i] % MOD;
	}
	for (int i = 2; i <= n; i++) ans[i] = (ans[i - 1] + C(i, n) * KSM(i, i - 2) % MOD) % MOD;
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
	read(n);
	read(T);
	read(c);
	MOD = c;
	Getans();
	while (T--)
	{
		read(l);
		read(r);
		if (!l) l++;
		printf("%lld\n", (ans[r] - ans[l - 1] + MOD) % MOD);
	}
	return 0;
}