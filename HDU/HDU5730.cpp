#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1<<18
#define MOD 313
using namespace std;

const double pi = acos(-1.0);

struct Complex
{
	double a, b;
	Complex() {}
	Complex(double _, double __): a(_), b(__) {}
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
int n, m, L, dp[MAXN], v[MAXN], rev[MAXN];

inline void FFT(Complex c[], int n, int f)
{
	Complex w, wn, x, y;
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

inline void CDQ(int l, int r)
{
	if (l == r)
	{
		dp[l] = (dp[l] + v[l]) % MOD;
		return ;
	}
	int mid = (l + r) >> 1;
	CDQ(l, mid);
	for (m = 1, L = 0; m <= r - l + 1; m <<= 1, L++);
	for (int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
	for (int i = 0; i < m; i++) a[i] = b[i] = Complex(0, 0);
	for (int i = l; i <= mid; i++) a[i - l] = Complex(dp[i], 0);
	for (int i = 0; i < r - l + 1; i++) b[i] = Complex(v[i + 1], 0);
	FFT(a, m, 1);
	FFT(b, m, 1);
	for (int i = 0; i < m; i++) a[i] = a[i] * b[i];
	FFT(a, m, -1);
	for (int i = mid + 1; i <= r; i++) dp[i] += (int)(a[i - l - 1].a + 0.5), dp[i] %= MOD;
	CDQ(mid + 1, r);
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
	while (true)
	{
		read(n);
		if (!n) break;
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; i++) read(v[i]), v[i] %= MOD;
		CDQ(1, n);
		printf("%d\n", dp[n]);
	}
	return 0;
}