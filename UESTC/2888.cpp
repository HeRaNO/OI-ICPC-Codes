// strict version
#include <cstdio>
#include <algorithm>
#define MAXK 100005

const int M = 998'244'353;
const int g = 3;

int n, Q, k;
int fac[MAXK], inv[MAXK], invfac[MAXK], Sk[MAXK];

int fadd(int x, int y){ x += y; if (x >= M) x -= M; return x; }
int fsub(int x, int y){ x -= y; if (x <  0) x += M; return x; }
int fmul(int x, int y){ return 1LL * x * y % M; }

int fpow(int a, int b)
{
	int r = 1;
	for (; b; b >>= 1, a = fmul(a, a))
		if (b & 1) r = fmul(r, a);
	return r;
}

void init(int k)
{
	fac[1] = inv[1] = invfac[0] = 1;
	for (int i = 2; i <= k + 1; i++)
		inv[i] = fmul(M - M / i, inv[M % i]);
	for (int i = 1; i <= k; i++)
		invfac[i] = fmul(invfac[i - 1], inv[i]);
	return ;
}

namespace Stirling
{
	int n, m, L, rev[1 << 18];
	int a[1 << 18], b[1 << 18], invn;

	void NTT(int c[], int n, int f)
	{
		int w, wn, x, y;
		for (int i = 0; i < n; i++)
			if (i < rev[i]) std::swap(c[i], c[rev[i]]);
		for (int i = 1; i < n; i <<= 1)
		{
			wn = fpow(g, (M - 1) / (i << 1));
			if (!~f) wn = fpow(wn, M - 2);
			for (int p = i << 1, j = 0; j < n; j += p)
			{
				w = 1;
				for (int k = 0; k < i; k++, w = fmul(w, wn))
				{
					x = c[j + k];
					y = fmul(c[j + k + i], w);
					c[j + k] = fadd(x, y);
					c[j + k + i] = fsub(x, y);
				}
			}
		}
		if (!~f)
			for (int i = 0; i < n; i++) c[i] = fmul(c[i], invn);
		return ;
	}

	inline void NTT_Prepare()
	{
		for (m = 1, L = 0; m <= (n << 1); L++, m <<= 1);
		invn = fpow(m, M - 2);
		for (int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
		return ;
	}

	inline void NTT_Work()
	{
		NTT(a, m, 1);
		NTT(b, m, 1);
		for (int i = 0; i < m; i++) a[i] = fmul(a[i], b[i]);
		NTT(a, m, -1);
		return ;
	}

	void Do(int k, int Sk[])
	{
		n = k;
		for (int i = 0; i <= k; i++)
		{
			a[i] = fmul(fpow(i, k), invfac[i]);
			b[i] = fmul((i & 1 ? M - 1 : 1), invfac[i]);
		}
		NTT_Prepare(); NTT_Work();
		for (int i = 0; i <= k; i++)
			Sk[i] = a[i];
		return ;
	}
}

int main()
{
	scanf("%d %d %d", &n, &k, &Q);
	init(k); Stirling::Do(k, Sk);
	int invQ = fpow(Q + 1, M - 2);
	int Qn = fpow(Q + 1, n); int Qn1 = fmul(Qn, invQ);
	int t = 1, Qj = 1, ans = 0;
	if (k == 0)
		ans = fsub(1, Qn);
	for (int j = 0; j <= k; j++)
	{
		int p = fadd(fmul(j + 1, Qn), fmul(fmul(Q, n - j), Qn1));
		p = fmul(p, inv[j + 1]);
		if (j == 0) p = fsub(p, 1);
		ans = fadd(ans, fmul(fmul(Sk[j], Qj), fmul(t, p)));
		t = fmul(t, n - j);
		Qn = fmul(Qn, invQ); Qn1 = fmul(Qn1, invQ); Qj = fmul(Qj, Q);
	}
	printf("%d\n", ans);
	return 0;
}