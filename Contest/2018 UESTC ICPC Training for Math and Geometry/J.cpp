#include <cstdio>
#define MAXN 2010
using namespace std;

const long long M = 1e9 + 7;

int n, a, b, c, d;
long long fac[MAXN], inv[MAXN], invfac[MAXN], ans;

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
	inv[1] = 1;
	invfac[1] = 1;
	fac[0] = 1;
	read(a);
	read(b);
	read(c);
	read(d);
	n = a + b + c + d;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % M;
	for (int i = 2; i <= n; i++) inv[i] = 1LL * (M - M / i) * inv[M % i] % M;
	for (int i = 2; i <= n; i++) invfac[i] = invfac[i - 1] * inv[i] % M;
	ans = fac[n];
	(ans *= invfac[a]) %= M;
	(ans *= invfac[b]) %= M;
	(ans *= invfac[c]) %= M;
	(ans *= invfac[d]) %= M;
	printf("%lld\n", ans);
	return 0;
}
