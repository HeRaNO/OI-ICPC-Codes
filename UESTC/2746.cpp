#include <cstdio>
#define MAXM 5005

const int M = 1'000'000'007;

int n, m, a;
int fac[MAXM], inv[MAXM], invfac[MAXM], f[MAXM];

void fadd(int &x, int y){ x += y; if (x >= M) x -= M; return ; }
int fsub(int x, int y){ x -= y; if (x <  0) x += M; return x; }
int fmul(int x, int y){ return 1LL * x * y % M; }

int fpow(int a, int b)
{
	int r = 1;
	for (; b; b >>= 1, a = fmul(a, a))
		if (b & 1) r = fmul(r, a);
	return r;
}

int C(int n, int m){ return fmul(fac[n], fmul(invfac[m], invfac[n - m])); }

void init(int n)
{
	fac[0] = inv[1] = invfac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fmul(fac[i - 1], i);
	for (int i = 2; i <= n; i++) inv[i] = fmul(M - M / i, inv[M % i]);
	for (int i = 1; i <= n; i++) invfac[i] = fmul(invfac[i - 1], inv[i]);
	return ;
}

int main()
{
	scanf("%d %d %d", &n, &m, &a);
	if (a == 1)
	{
		init(m + 1);
		f[0] = n + 1;
		int t = n + 1;
		for (int k = 1; k <= m; k++)
		{
			t = fmul(t, n + 1);
			int s = 0;
			for (int i = 0; i < k; i++)
				fadd(s, fmul(C(k + 1, i), f[i]));
			f[k] = fmul(fsub(t, s), inv[k + 1]);
		}
	}
	else
	{
		init(m);
		int t = fpow(a, n), _a1 = fpow(a - 1, M - 2);
		int R = fmul(a, _a1);
		f[0] = fmul(fsub(fmul(t, a), 1), _a1);
		for (int x = 1; x <= m; x++)
		{
			t = fmul(t, n + 1);
			int s = 0;
			for (int i = 0; i < x; i++)
				fadd(s, fmul(C(x, i), f[i]));
			f[x] = fmul(R, fsub(t, s));
		}
	}
	int ans = 0;
	for (int i = 0; i <= m; i++)
	{
		int b; scanf("%d", &b);
		fadd(ans, fmul(b, f[i]));
	}
	printf("%d\n", ans);
	return 0;
}