#include <bits/stdc++.h>
#define MAXP 40000
#define MAXN 200010
using namespace std;

const long long M = 1e9 + 7;

int n, m, k, cnt[MAXP];
long long ans = 1, fac[MAXN], inv[MAXN], invfac[MAXN];

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	bool f = false;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	if (f) x = -x;
	return ;
}

int main()
{
	read(n);
	read(m);
	int q = m, p = sqrt(m);
	if (n == 1)
	{
		puts("1");
		return 0;
	}
	fac[0] = invfac[0] = 1;
	inv[1] = 1;
	for (int i = 1; i <= (n << 1); i++) fac[i] = fac[i - 1] * i % M;
	for (int i = 2; i <= (n << 1); i++) inv[i] = (M - M / i) * inv[M % i] % M;
	for (int i = 1; i <= (n << 1); i++) invfac[i] = invfac[i - 1] * inv[i] % M;
	for (int i = 2; i <= p; i++)
		while (!(q % i))
		{
			++cnt[i];
			q /= i;
			++k;
		}
	if (q != 1) ++k;
	for (int i = 1; i <= p; i++)
		if (cnt[i])
		{
			long long p = fac[cnt[i] + n - 1] * invfac[cnt[i]] % M * invfac[n - 1] % M;
			ans = ans * p % M;
		}
	if (q != 1) ans = (ans * n) % M;
	printf("%lld\n", ans);
	return 0;
}