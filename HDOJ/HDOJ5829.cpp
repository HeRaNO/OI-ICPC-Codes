#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN (1<<18)+5
#define MOD 998244353LL
#define g 3LL
using namespace std;

int n, m, L, T, A[MAXN], rev[MAXN];
long long inv[MAXN], fac[MAXN], invfac[MAXN];
long long a[MAXN], b[MAXN];
long long ans_i, pre_ans_i, coe;

inline bool cmp(long long a, long long b)
{
	return a > b;
}

inline long long Quick_MOD(long long a, long long b)
{
	long long res = 1, base = a;
	while (b)
	{
		if (b & 1) res = (res * base) % MOD;
		base = (base * base) % MOD;
		b >>= 1;
	}
	return res;
}

inline void NTT(long long c[], int n, int f)
{
	long long w, wn, x, y;
	for (int i = 0; i < n; i++)
		if (i < rev[i]) swap(c[i], c[rev[i]]);
	for (int i = 1; i < n; i <<= 1)
	{
		wn = Quick_MOD(g, (MOD - 1) / (i << 1));
		if (!~f) wn = Quick_MOD(wn, MOD - 2);
		for (int p = i << 1, j = 0; j < n; j += p)
		{
			w = 1LL;
			for (int k = 0; k < i; k++, w = w * wn % MOD)
			{
				x = c[j + k];
				y = c[j + k + i] * w % MOD;
				c[j + k] = (x + y) % MOD;
				c[j + k + i] = (x - y + MOD) % MOD;
			}
		}
	}
	if (!~f)
		for (int i = 0; i < n; i++) c[i] = c[i] * inv[n] % MOD;
	return ;
}

inline void PreWork()
{
	invfac[0] = fac[0] = inv[1] = fac[1] = invfac[1] = 1LL;
	for (int i = 2; i < MAXN; i++)
	{
		fac[i] = (fac[i - 1] * i) % MOD;
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
		invfac[i] = (invfac[i - 1] * inv[i]) % MOD;
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
	PreWork();
	read(T);
	while (T--)
	{
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		read(n);
		for (m = 1, L = 0; m <= (n << 1); L++, m <<= 1);
		for (int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
		for (int i = 0; i < n; i++) read(A[i]);
		sort(A, A + n, cmp);
		for (int i = 0; i < n; i++) a[i] = Quick_MOD(2, n - i) * invfac[i] % MOD;
		for (int i = 0; i < n; i++) b[i] = fac[i] * (long long)A[i] % MOD;
		reverse(b, b + n);
		NTT(a, m, 1);
		NTT(b, m, 1);
		for (int i = 0; i < m; i++) a[i] = a[i] * b[i] % MOD;
		NTT(a, m, -1);
		ans_i = pre_ans_i = 0LL;
		coe = inv[2];
		for (int i = 1; i <= n; i++)
		{
			ans_i = coe * invfac[i - 1] % MOD * a[n - i] % MOD;
			ans_i = (ans_i + pre_ans_i) % MOD;
			printf("%lld ", ans_i);
			coe = coe * inv[2] % MOD;
			swap(ans_i, pre_ans_i);
		}
		putchar('\n');
	}
	return 0;
}