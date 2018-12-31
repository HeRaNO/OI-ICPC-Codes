#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1<<18
//the length is 2^L,2^L is the first number that not smaller than the degree of the polynomial
using namespace std;

//FFT part
namespace FFT
{
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

	Complex a[MAXN], b[MAXN];
	int n, m, L, rev[MAXN], ans[MAXN];

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

	inline void FFT_Prepare()
	{
		for (m = 1, L = 0; m <= (n << 1); m <<= 1, L++);
		for (int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
		return ;
	}

	inline void FFT_Work()
	{
		FFT(a, m, 1);
		FFT(b, m, 1);
		for (int i = 0; i < m; i++) a[i] = a[i] * b[i];
		FFT(a, m, -1);
		for (int i = 0; i < (n << 1); i++) ans[i] = (int)(a[i].a + 0.5);
		return ;
	}
}

//NTT Part
namespace NTT
{
	//Please use getG() first to get the primitive root.
	inline long long Quick_MOD(long long a, long long b, long long MOD)
	{
		long long r = 1, t = a;
		while (b)
		{
			if (b & 1) r = (r * t) % MOD;
			t = (t * t) % MOD;
			b >>= 1;
		}
		return r;
	}

	long long p[MAXN];
	inline int getG(long long MOD)
	{
		long long x = MOD - 1;
		int tot = 0;
		for (int i = 2; x - 1; i++)
			if (!(x % i))
			{
				p[++tot] = i;
				while (!(x % i)) x /= i;
			}
		for (int i = 2; i <= MOD; i++)
		{
			bool flag = true;
			for (int j = 1; j <= tot && flag; j++)
				if (Quick_MOD(i, (MOD - 1) / p[j], MOD) == 1) flag = false;
			if (flag) return i;
		}
		return -1;
	}

	long long a[MAXN], b[MAXN];
	int n, m, L, rev[MAXN];
	long long g, invn, MOD;

	inline void NTT(long long c[], int n, int f)
	{
		long long w, wn, x, y;
		for (int i = 0; i < n; i++)
			if (i < rev[i]) swap(c[i], c[rev[i]]);
		for (int i = 1; i < n; i <<= 1)
		{
			wn = Quick_MOD(g, (MOD - 1) / (i << 1), MOD);
			if (!~f) wn = Quick_MOD(wn, MOD - 2, MOD);
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
			for (int i = 0; i < n; i++) c[i] = c[i] * invn % MOD;
		return ;
	}

	inline void NTT_Prepare()
	{
		for (m = 1, L = 0; m <= (n << 1); L++, m <<= 1);
		g = getG(MOD);
		invn = Quick_MOD(m, MOD - 2, MOD);
		for (int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
		return ;
	}

	inline void NTT_Work()
	{
		NTT(a, m, 1);
		NTT(b, m, 1);
		for (int i = 0; i < m; i++) a[i] = (a[i] * b[i]) % MOD;
		NTT(a, m, -1);
		return ;
	}
}

//FWT Part
namespace FWT
{
	int a[MAXN], b[MAXN], n, m;

	inline void FWT_And(int c[], int n, int f)
	{
		int x, y;
		for (int i = 1; i < n; i <<= 1)
			for (int p = i << 1, j = 0; j < n; j += p)
				for (int k = 0; k < i; k++)
				{
					x = c[j + k], y = c[j + k + i];
					c[j + k] = x + y * f;
				}
		return ;
	}

	inline void FWT_Or(int c[], int n, int f)
	{
		int x, y;
		for (int i = 1; i < n; i <<= 1)
			for (int p = i << 1, j = 0; j < n; j += p)
				for (int k = 0; k < i; k++)
				{
					x = c[j + k];
					y = c[j + k + i];
					c[j + k + i] = y + x * f;
				}
		return ;
	}

	inline void FWT_Xor(int c[], int n, bool f) //f=true means it will do UFWT
	{
		int x, y;
		for (int i = 1; i < n; i <<= 1)
			for (int p = i << 1, j = 0; j < n; j += p)
				for (int k = 0; k < i; k++)
				{
					x = c[j + k];
					y = c[j + k + i];
					c[j + k] = x + y;
					c[j + k + i] = x - y;
					if (f)
					{
						c[j + k] >>= 1;
						c[j + k + i] >>= 1;
					}
				}
		return ;
	}

	inline void FWT_Prepare()
	{
		for (m = 1; m <= n; m <<= 1);
		return ;
	}

	inline void FWT_Work()
	{
		FWT_And(a, m, 1);
		FWT_And(b, m, 1);
		for (int i = 0; i < m; i++) a[i] *= b[i];
		FWT_And(a, m, -1);
		/*  FWT_Xor(a,m,false);FWT_Xor(a,m,false);
		    for (int i=0;i<m;i++) a[i]*=b[i];
		    FWT_Xor(a,m,true);*/
		return ;
	}
}

int main()
{
	return 0;
}