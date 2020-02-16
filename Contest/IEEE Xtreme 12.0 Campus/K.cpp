#include <bits/stdc++.h>
#define MAXN 1<<19
using namespace std;

const double pi = acos(-1.0);

struct Complex
{
	double a, b;
	Complex() {}
	Complex(double _a, double _b): a(_a), b(_b) {}
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

Complex a[MAXN];
int n, T, TT, m, L, mxl, rev[MAXN], len[MAXN], k;
long long all, ans, tot[MAXN], cnt[MAXN];

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
	//freopen("in","r",stdin);freopen("my","w",stdout);
	read(T);
	while (T--)
	{
		memset(cnt, 0, sizeof cnt);
		read(n);read(TT);
		for (int i = 0; i < n; i++) read(len[i]), ++cnt[len[i]];
		sort(len, len + n);
		mxl = len[n - 1];
		for (m = 1, L = 0; m <= (mxl << 1); m <<= 1, L++);
		for (int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
		for (int i = 0; i <= mxl; i++) a[i] = Complex(cnt[i], 0);
		for (int i = mxl + 1; i < m; i++) a[i] = Complex(0, 0);
		FFT(a, m, 1);
		for (int i = 0; i < m; i++) a[i] = a[i] * a[i];
		FFT(a, m, -1);
		for (int i = 0; i < m; i++) tot[i] = (long long)(a[i].a + 0.5);
		for (int i = 0; i < n; i++) tot[len[i] << 1]--;
		for (int i = 0; i < m; i++) tot[i] >>= 1LL;
		for (int i = m; i; i--) tot[i - 1] += tot[i];
		while (TT--)
		{
			read(k);
			printf("%lld\n", tot[k]);
		}
	}
	return 0;
}