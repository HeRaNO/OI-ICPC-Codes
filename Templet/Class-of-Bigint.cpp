#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXL 2000
#define MAXN 1<<15
#define mymax(a,b) a>b?a:b
#define mymin(a,b) a<b?a:b
using namespace std;

const int P = 8;
const long long BASE = 1e8;
//If you use FastMul,the recommend P is 6.
//If you use division,the recommend P is 5.
const long double pi = acos(-1.0);
char buf[MAXL];
int rev[MAXN];

struct Complex
{
	long double a, b;
	Complex() {}
	Complex(long double _a, long double _b): a(_a), b(_b) {}
	Complex operator + (const Complex &z)const
	{
		return Complex(a + z.a, b + z.b);
	}
	Complex operator - (const Complex &z)const
	{
		return Complex(a - z.a, b - z.b);
	}
	Complex operator * (const Complex &z)const
	{
		return Complex(a * z.a - b * z.b, a * z.b + b * z.a);
	}
} A[MAXL], B[MAXL];

struct longint
{
	long long s[MAXL];
	int len;
	bool neg;
	//s is an array that record the number.it start at 0 and it is reversed.
	//len is the last non-zero position.
	//if neg is true,the interger is negative.
	longint(): len(0), neg(false)
	{
		memset(s, 0, sizeof s);
	}
	//Reset input and output.
	longint operator = (const char *);
	longint operator = (const long long &);
	void read();
	void write();
	//Reset compare
	bool operator < (const longint &)const ;
	bool operator > (const longint &)const ;
	bool operator <= (const longint &)const ;
	bool operator >= (const longint &)const ;
	bool operator == (const longint &)const ;
	bool operator != (const longint &)const ;
	//Reset arithmetic.
	longint operator + (const longint &)const ;
	longint operator + (const long long &)const ;
	longint operator ++ ();
	longint operator += (const longint &);
	longint operator += (const long long &);

	longint operator - (const longint &)const ;
	longint operator - (const long long &)const ;
	longint operator -- ();
	longint operator -= (const longint &);
	longint operator -= (const long long &);

	longint operator * (const longint &)const ;
	longint operator * (const long long &)const ;
	longint operator *= (const longint &);
	longint operator *= (const long long &);

	longint operator / (const longint &)const ;
	longint operator / (const long long &)const ;
	longint operator /= (const longint &);
	longint operator /= (const long long &);

	longint operator % (const longint &)const ;
	longint operator % (const long long &)const ;
	longint operator %= (const longint &);
	longint operator %= (const long long &);
	//Useful operating.
	void FFT(Complex [], int, int);
	longint FastMul(const longint &); //FFT in fact.
};

longint longint::operator = (const char *a)
{
	int n = strlen(a), i;
	if (a[0] == '-')
	{
		i = 1;
		neg = true;
		for (long long w = 1LL; i < n; i++, w = (w << 3) + (w << 1))
		{
			if (!(i % P) && i)
			{
				w = 1LL;
				len++;
			}
			s[len] += w * (a[n - i] - '0');
		}
	}
	else
	{
		i = 0;
		for (long long w = 1LL; i < n; i++, w = (w << 3) + (w << 1))
		{
			if (!(i % P) && i)
			{
				w = 1LL;
				len++;
			}
			s[len] += w * (a[n - 1 - i] - '0');
		}
	}
	while (len && !s[len]) len--;
	return *this;
}

longint longint::operator = (const long long &a)
{
	long long b = a;
	if (a < 0)
	{
		neg = true;
		b = -a;
	}
	long long w = 1LL;
	int i = 0;
	while (b)
	{
		if (!(i % P) && i)
		{
			w = 1LL;
			len++;
		}
		s[len] += w * (b % 10LL);
		b /= 10LL;
		w = (w << 3) + (w << 1);
		i++;
	}
	return *this;
}

void longint::read()
{
	memset(s, 0, sizeof s);
	len = 0;
	neg = false;
	scanf("%s", buf);
	*this = buf;
	return ;
}

void longint::write()
{
	if (neg) putchar('-');
	printf("%lld", s[len]);
	for (int i = len - 1; ~i; i--) printf("%0*lld", P, s[i]);
	putchar('\n');
	return ;
}

bool longint::operator < (const longint &a)const
{
	if (neg ^ a.neg) return neg;
	if (len != a.len) return len < a.len;
	for (int i = mymax(len, a.len); ~i; i--)
		if (s[i] != a.s[i]) return neg ? s[i] > a.s[i] : s[i] < a.s[i];
	return false;
}

bool longint::operator > (const longint &a)const
{
	return a < *this;
}

bool longint::operator <= (const longint &a)const
{
	return !(*this > a);
}

bool longint::operator >= (const longint &a)const
{
	return !(*this < a);
}

bool longint::operator == (const longint &a)const
{
	if ((neg ^ a.neg) || (len != a.len)) return false;
	for (int i = len; ~i; i--) if (s[i] != a.s[i]) return false;
	return true;
}

bool longint::operator != (const longint &a)const
{
	return !(a == *this);
}

longint longint::operator + (const longint &a)const
{
	if (neg ^ a.neg)
	{
		longint t = neg ? *this : a;
		t.neg = false;
		return neg ? a - t : *this - t;
	}
	longint res;
	int w = 0, n = mymax(len, a.len);
	for (int i = 0, t; w || i <= n; i++)
	{
		t = s[i] + a.s[i] + w;
		res.s[res.len++] = t % BASE;
		w = t / BASE;
	}
	res.neg = neg;
	while (res.len && !res.s[res.len]) res.len--;
	return res;
}

longint longint::operator + (const long long &a)const
{
	longint b;
	b = a;
	return *this + b;
}

longint longint::operator ++()
{
	longint a;
	a = 1;
	*this = *this + a;
	return *this;
}

longint longint::operator += (const longint &a)
{
	*this = *this + a;
	return *this;
}

longint longint::operator += (const long long &a)
{
	longint b;
	b = a;
	*this = *this + b;
	return *this;
}

longint longint::operator - (const longint &num)const
{
	longint b = num, a = *this;
	if (a.neg && b.neg)
	{
		a.neg = b.neg = false;
		return b - a;
	}
	if (b.neg)
	{
		b.neg = false;
		return a + b;
	}
	if (a.neg)
	{
		a.neg = false;
		longint c = (a + b);
		c.neg = true;
		return c;
	}
	if (a < b)
	{
		longint c = (b - a);
		c.neg = true;
		return c;
	}
	longint c;
	c.len = a.len;
	for (int i = 0; i <= a.len; i++)
	{
		c.s[i] += a.s[i] - b.s[i];
		if (c.s[i] < 0)
		{
			c.s[i] += BASE;
			c.s[i + 1]--;
		}
	}
	while (c.len && !c.s[c.len]) c.len--;
	return c;
}

longint longint::operator - (const long long &a)const
{
	longint b;
	b = a;
	return *this - b;
}

longint longint::operator -- ()
{
	longint a;
	a = -1;
	*this = *this + a;
	return *this;
}

longint longint::operator -= (const longint &a)
{
	*this = *this - a;
	return *this;
}

longint longint::operator -= (const long long &a)
{
	longint b;
	b = a;
	*this = *this - b;
	return *this;
}

longint longint::operator * (const longint &a)const
{
	longint res;
	res.len = len + a.len;
	for (int i = 0; i <= len; i++)
		for (int j = 0; j <= a.len; j++)
			res.s[i + j] += s[i] * a.s[j];
	for (int i = 0; i <= res.len; i++)
		if (res.s[i] >= BASE)
		{
			res.s[i + 1] += res.s[i] / BASE;
			res.s[i] %= BASE;
		}
	while (res.s[res.len]) res.len++;
	while (res.len && !res.s[res.len]) res.len--;
	res.neg = neg ^ a.neg;
	return res;
}

longint longint::operator * (const long long &a)const
{
	longint b;
	b = a;
	return *this * b;
}

longint longint::operator *= (const longint &a)
{
	*this = *this * a;
	return *this;
}

longint longint::operator *= (const long long &a)
{
	longint b;
	b = a;
	*this = *this * b;
	return *this;
}

longint longint::operator / (const longint &p)const
{
	longint res, a = *this, b = p, c;
	bool aneg = a.neg, bneg = b.neg;
	if (a.len < b.len) return res;
	a.neg = b.neg = false;
	res.len = a.len - b.len;
	for (int i = res.len; ~i; i--)
	{
		memset(c.s, 0, sizeof c.s);
		c.len = b.len + i;
		for (int j = 0; j <= b.len; j++) c.s[j + i] = b.s[j];
		while (a >= c) res.s[i]++, a -= c;
	}
	res.neg = aneg ^ bneg;
	while (res.len && !res.s[res.len]) res.len--;
	return res;
}

longint longint::operator / (const long long &a)const
{
	longint b;
	b = a;
	return *this / b;
}

longint longint::operator /= (const longint &a)
{
	*this = *this / a;
	return *this;
}

longint longint::operator /= (const long long &a)
{
	longint b;
	b = a;
	*this = *this / b;
	return *this;
}

longint longint::operator % (const longint &b)const
{
	longint a = *this, c, f;
	f = (a / b) * b;
	c = a - f;
	return c;
}

longint longint::operator % (const long long &a)const
{
	longint b;
	b = a;
	return *this % b;
}

longint longint::operator %= (const longint &a)
{
	*this = *this % a;
	return *this;
}

longint longint::operator %= (const long long &a)
{
	longint b;
	b = a;
	*this = *this % b;
	return *this;
}

void longint::FFT(Complex c[], int n, int f)
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

longint longint::FastMul(const longint &q)
{
	longint p = *this, c;
	int n = p.len + q.len, m, L;
	c.len = n;
	for (m = 1, L = 0; m <= n; m <<= 1, L++);
	for (int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
	memset(A, 0, sizeof A);
	memset(B, 0, sizeof B);
	for (int i = 0; i <= p.len; i++) A[i] = Complex(p.s[i], 0);
	for (int i = 0; i <= q.len; i++) B[i] = Complex(q.s[i], 0);
	FFT(A, m, 1);
	FFT(B, m, 1);
	for (int i = 0; i < m; i++) A[i] = A[i] * B[i];
	FFT(A, m, -1);
	for (int i = 0; i <= n; i++) c.s[i] = (long long)(A[i].a + 0.5);
	for (int i = 0; i <= n; i++)
		if (c.s[i] >= BASE)
		{
			c.s[i + 1] += c.s[i] / BASE;
			c.s[i] %= BASE;
		}
	while (c.len && c.s[c.len]) c.len++;
	while (c.len && !c.s[c.len]) c.len--;
	c.neg = p.neg ^ q.neg;
	return c;
}

int main()
{
	return 0;
}