#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 1<<18
using namespace std;

const double pi = acos(-1.0);

struct Complex
{
	double a, b;
	Complex() {}
	Complex(double _a, double _b): a(_a), b(_b) {}
	Complex(double _a): a(_a), b(0.0) {}
	inline Complex operator + (const Complex &z)const
	{
		return Complex(a + z.a, b + z.b);
	}
	inline Complex operator - (const Complex &z)const
	{
		return Complex(a - z.a, b - z.b);
	}
	inline Complex operator * (const Complex &z)const
	{
		return Complex(a * z.a - b * z.b, a * z.b + b * z.a);
	}
};

Complex a[MAXN], b[MAXN];
int n, m, L, x, rev[MAXN];

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

inline int read()
{
	int x = 0;
	bool f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = 0;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return f ? x : -x;
}

int main()
{
	n = read();
	for (int i = 0; i < n; i++) a[i].a = read(), b[n - i - 1].a = read();
	for (m = 1; m < (n << 1); m <<= 1, L++);
	for (int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
	FFT(a, m, 1);
	FFT(b, m, 1);
	for (int i = 0; i < m; i++) a[i] = a[i] * b[i];
	FFT(a, m, -1);
	for (int i = n - 1; i < (n << 1) - 1; i++) printf("%d\n", (int)(a[i].a + 0.5));
	return 0;
}