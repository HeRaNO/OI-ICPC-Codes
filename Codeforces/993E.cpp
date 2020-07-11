#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 1<<19
using namespace std;

const double pi = acos(-1.0);

struct Complex
{
	double a, b;
	Complex() {}
	Complex(double _a, double _b): a(_a), b(_b) {}
	inline Complex operator +(const Complex &z)const{
		return Complex(a + z.a, b + z.b);
	}
	inline Complex operator -(const Complex &z)const{
		return Complex(a - z.a, b - z.b);
	}
	inline Complex operator *(const Complex &z)const{
		return Complex(a * z.a - b * z.b, a * z.b + b * z.a);
	}
};

Complex a[MAXN], b[MAXN];
int n, m, x, L, rev[MAXN], cnt[MAXN], c[MAXN];
long long ans[MAXN];

inline void FFT(Complex c[], int n, int f)
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
				x = c[j + k]; y = w * c[j + k + i];
				c[j + k] = x + y; c[j + k + i] = x - y;
			}
		}
	}
	if (!~f)
		for (int i = 0; i < n; i++) c[i].a /= (double)n;
	return ;
}

inline void FFT_Prepare()
{
	for (m = 1, L = 0; m <= (n << 1); m <<= 1, L++);
	for (int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
	return ;
}

inline void FFT_Work()
{
	FFT(a, m, 1); FFT(b, m, 1);
	for (int i = 0; i < m; i++) a[i] = a[i] * b[i];
	FFT(a, m, -1);
	for (int i = 0; i < (n << 1); i++) ans[i] = (long long)(a[i].a + 0.5);
	return ;
}

int main()
{
	scanf("%d %d", &n, &x); cnt[0] = 1;
	for (int i = 1, y; i <= n; i++)
	{
		scanf("%d", &y);
		c[i] = c[i - 1] + (y < x);
		++cnt[c[i]];
	}
	for (int i = 0; i <= n; i++)
	{
		a[i].a = cnt[i];
		b[i].a = cnt[n - i];
	}
	FFT_Prepare(); FFT_Work();
	ans[n] -= n + 1; ans[n] >>= 1;
	for (int i = n; ~i; i--) printf("%lld%c", ans[i], i ? ' ' : '\n');
	return 0;
}