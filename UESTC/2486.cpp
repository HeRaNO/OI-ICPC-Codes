#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN (1<<19)+5
using namespace std;

const long long M = 998244353;
const long long g = 3;

int n, m, L, A[MAXN], rev[MAXN];
long long inv[MAXN], fac[MAXN], invfac[MAXN];
long long a[MAXN], b[MAXN];
long long ans_i, pre_ans_i, coe, _inv2, invm;

inline long long fpow(long long a, long long b)
{
	long long r = 1;
	for (; b; b >>= 1, (a *= a) %= M) if (b & 1) (r *= a) %= M;
	return r;
}

inline void NTT(long long c[], int n, int f)
{
	long long w, wn, x, y;
	for (int i = 0; i < n; i++)
		if (i < rev[i]) swap(c[i], c[rev[i]]);
	for (int i = 1; i < n; i <<= 1)
	{
		wn = fpow(g, (M - 1) / (i << 1));
		if (!~f) wn = fpow(wn, M - 2);
		for (int p = i << 1, j = 0; j < n; j += p)
		{
			w = 1LL;
			for (int k = 0; k < i; k++, w = w * wn % M)
			{
				x = c[j + k];
				y = c[j + k + i] * w % M;
				c[j + k] = (x + y) % M;
				c[j + k + i] = (x - y + M) % M;
			}
		}
	}
	if (!~f)
		for (int i = 0; i < n; i++) c[i] = c[i] * invm % M;
	return ;
}

inline void PreWork(int n)
{
	n = max(n, 2);
	invfac[0] = fac[0] = inv[1] = fac[1] = invfac[1] = 1LL;
	for (int i = 2; i <= n; i++)
	{
		fac[i] = (fac[i - 1] * i) % M;
		inv[i] = (M - M / i) * inv[M % i] % M;
		invfac[i] = (invfac[i - 1] * inv[i]) % M;
	}
	_inv2 = inv[2];
	for (m = 1, L = 0; m <= (n << 1); L++, m <<= 1);
	for (int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
	invm = fpow(m, M - 2);
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
	PreWork(n);
	for (int i = 0; i < n; i++) read(A[i]);
	sort(A, A + n);
	for (int i = 0; i < n; i++) a[i] = fpow(2, n - i) * invfac[i] % M;
	for (int i = 0; i < n; i++) b[i] = fac[i] * A[i] % M;
	reverse(b, b + n);
	NTT(a, m, 1);
	NTT(b, m, 1);
	for (int i = 0; i < m; i++) a[i] = a[i] * b[i] % M;
	NTT(a, m, -1);
	coe = _inv2;
	for (int i = 1; i <= n; i++)
	{
		ans_i = coe * invfac[i - 1] % M * a[n - i] % M;
		ans_i = (ans_i + pre_ans_i) % M;
		printf("%lld\n", ans_i);
		coe = coe * _inv2 % M;
		swap(ans_i, pre_ans_i);
	}
	return 0;
}