#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1<<18
using namespace std;

const long double pi = acos(-1.0);

struct Complex
{
	long double a, b;
	Complex() {}
	Complex(long double _a, long double _b): a(_a), b(_b) {}
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

Complex a[MAXN], b[MAXN], c[MAXN];
int n, m, T, L, x, rev[MAXN], s[MAXN], cnt;
long long res;

inline void Clear(bool f)
{
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	if (!f) memset(c, 0, sizeof c);
	return ;
}

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
		for (int i = 0; i < n; i++) c[i].a /= (long double)n;
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
	read(T);
	while (T--)
	{
		read(n);
		res = 0LL;
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			read(x);
			s[i] = s[i - 1] + x;
			if (!x)
			{
				cnt++;
				res += cnt * (cnt + 1) >> 1;
			}
			else cnt = 0;
		}
		printf("%lld\n", res);
		for (m = 1, L = 0; m < (s[n] << 1); m <<= 1, L++);
		for (int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
		Clear(0);
		for (int i = 1; i <= n; i++) a[s[i]].a += i, b[s[n] - s[i - 1]].a += 1;
		FFT(a, m, 1);
		FFT(b, m, 1);
		for (int i = 0; i < m; i++) c[i] = a[i] * b[i];
		FFT(c, m, -1);
		Clear(1);
		for (int i = 1; i <= n; i++) a[s[i]].a += 1, b[s[n] - s[i - 1]].a += i - 1;
		FFT(a, m, 1);
		FFT(b, m, 1);
		for (int i = 0; i < m; i++) a[i] = a[i] * b[i];
		FFT(a, m, -1);
		for (int i = 0; i < m; i++) c[i] = c[i] - a[i];
		for (int i = 1; i <= s[n]; i++) printf("%lld\n", (long long)(c[i + s[n]].a + 0.5));;
	}
	return 0;
}