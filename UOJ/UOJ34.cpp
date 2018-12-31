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
int n, m, len, R, L, rev[MAXN];

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
	m = read();
	len = n + m + 2;
	for (int i = 0; i <= n; i++) a[i].a = read();
	for (int i = 0; i <= m; i++) b[i].a = read();
	for (R = 1; R < len; R <<= 1, L++);
	for (int i = 0; i < R; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
	FFT(a, R, 1);
	FFT(b, R, 1);
	for (int i = 0; i < R; i++) a[i] = a[i] * b[i];
	FFT(a, R, -1);
	for (int i = 0; i < len - 1; i++) printf("%d%c", (int)(a[i].a + 0.5), i == len - 2 ? '\n' : ' ');
	return 0;
}