#include <cstdio>
#define N 1000010
using namespace std;

const long long M = 1e6 + 3;

long long fac[N], inv[N], invfac[N];
int T, n, l, r, m;

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

inline long long C(int n, int m)
{
	if (n < m) return 0LL;
	if (n < M && m < M) return fac[n] * invfac[m] % M * invfac[n - m] % M;
	return C(n / M, m / M) * C(n % M, m % M) % M;
}

int main()
{
	fac[0] = fac[1] = inv[1] = invfac[0] = invfac[1] = 1LL;
	for (int i = 2; i < N; i++)
	{
		fac[i] = fac[i - 1] * i % M;
		inv[i] = (M - M / i) * inv[M % i] % M;
	}
	for (int i = 1; i < N; i++) invfac[i] = invfac[i - 1] * inv[i] % M;
	read(T);
	while (T--)
	{
		read(n);
		read(l);
		read(r);
		m = r - l + 1;
		printf("%lld\n", (C(n + m, m) - 1 + M) % M);
	}
	return 0;
}