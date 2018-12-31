#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1<<15
#define MOD 119
using namespace std;

const double pi = acos(-1.0);

struct Complex
{
	double a, b;
	Complex() {}
	Complex(double _a, double _b): a(_a), b(_b) {}
	inline Complex operator +(const Complex &z)const
	{
		return Complex(a + z.a, b + z.b);
	}
	inline Complex operator -(const Complex &z)const
	{
		return Complex(a - z.a, b - z.b);
	}
	inline Complex operator *(const Complex &z)const
	{
		return Complex(a * z.a - b * z.b, a * z.b + b * z.a);
	}
};

Complex A[MAXN], B[MAXN];
int n, m, L, a, b, p, q, f[MAXN], rev[MAXN], coe[MAXN];
int ans[MAXN], base[MAXN];

__attribute__((__optimize__("-O2"))) inline void FFT(Complex c[], int n, int f)
{
	Complex wn, w, x, y;
	for (int i = 0; i < n; i++)
		if (i < rev[i]) swap(c[i], c[rev[i]]);
	for (int i = 1; i < n; i <<= 1)
	{
		wn = Complex(cos(pi / i), sin(pi / i) * f);
		for (int p = i << 1, j = 0; j < n; j += p)
		{
			w = Complex(1, 0);
			for (int k = 0; k < i; k++, w = w * wn)
			{
				x = c[j + k];
				y = w * c[j + k + i];
				c[j + k] = x + y;
				c[j + k + i] = x - y;
			}
		}
	}
	if (!~f)
		for (int i = 0; i < n; i++) c[i].a /= (double)n;
	return ;
}

__attribute__((__optimize__("-O2"))) inline void Multiply(int x[], int y[])
{
	for (int i = 0; i < m; i++) A[i] = Complex(x[i], 0), B[i] = Complex(y[i], 0);
	FFT(A, m, 1);
	FFT(B, m, 1);
	for (int i = 0; i < m; i++) A[i] = A[i] * B[i];
	FFT(A, m, -1);
	for (int i = 0; i < m; i++) coe[i] = (int)(A[i].a + 0.5) % MOD;
	for (int i = m - 1; i > q; i--)
		if (coe[i])
		{
			coe[i - q] = (coe[i - q] + coe[i] * b) % MOD;
			coe[i - p] = (coe[i - p] + coe[i] * a) % MOD;
		}
	for (int i = 0; i <= q; i++) x[i] = coe[i];
	return ;
}

__attribute__((__optimize__("-O2"))) int main()
{
	while (~scanf("%d %d %d %d %d", &n, &a, &b, &p, &q))
	{
		memset(f, 0, sizeof f);
		f[0] = 1;
		a %= MOD;
		b %= MOD;
		for (int i = 1; i <= q; i++)
		{
			if (i < p) f[i] = (f[i] + a + b) % MOD;
			else f[i] = (f[i] + a * f[i - p] + b) % MOD;
		}
		if (n <= q)
		{
			printf("%d\n", f[n]);
			continue;
		}
		for (m = 1, L = 0; m <= (q << 1); m <<= 1, L++);
		for (int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
		memset(ans, 0, sizeof ans);
		memset(base, 0, sizeof base);
		ans[0] = base[1] = 1;
		while (n)
		{
			if (n & 1) Multiply(ans, base);
			Multiply(base, base);
			n >>= 1;
		}
		for (int i = 0; i <= q; i++) n = (n + f[i] * ans[i]) % MOD;
		printf("%d\n", n);
	}
	return 0;
}