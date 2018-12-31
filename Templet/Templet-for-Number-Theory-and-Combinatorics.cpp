#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10010//You can change it if the problem needs.
//All MOD below must be prime if not explained.
using namespace std;

long long gcd(long long a, long long b)
{
	return b ? a : gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
	return a * b / gcd(a, b);
}

/*
    By using exgcd(a,b,x,y),you can get one solution of the equation:
    ax+by==gcd(a,b)
*/
long long exgcd(long long a, long long b, long long &x, long long &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long res = exgcd(b, a % b, x, y);
	long long t = x;
	x = y;
	y = t - (a / b) * y;
	return res;
}

//By using phi(n),you can get the Euler function of n
long long get_phi(long long x)
{
	long long res = x;
	for (long long i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			res /= i;
			res *= (i - 1);
			while (x % i == 0) x /= i;
		}
	}
	if (x != 1) res /= x, res *= (x - 1);
	return res;
}

/*
    China Remainer Theory is an algorithm to solve linear congruent equations.Like:
    x==a1 (mod m1)
    x==a2 (mod m2)
    ...
    x==an (mod mn)
    Each a is coprime.
    If not,you should use exCRT(n).
    By using CRT(n),you can get the minimum solution of the equations.
*/
long long a[MAXN], m[MAXN];
inline long long CRT(int n)
{
	long long M = 1, ans = 0;
	for (int i = 1; i <= n; i++) M *= m[i];
	for (int i = 1; i <= n; i++)
	{
		long long w = M / m[i], x, y;
		exgcd(w, m[i], x, y);
		ans = (ans + x * w * a[i]) % M;
	}
	return (ans + M) % M;
}

inline long long exCRT(int n)
{
	long long M = m[1], ans = a[1], x, y;
	for (int i = 2; i <= n; i++)
	{
		long long g = exgcd(M, m[i], x, y);
		if ((a[i] - ans) % g) return -1LL;
		x = (a[i] - ans) / g * x % (m[i] / g);
		ans += x * M;
		M = M / g * m[i];
		ans %= M;
	}
	return (ans + M) % M;
}

//By using Linear_Shaker(),you can get prime,Euler's function and Mobius's function in [1,n].
long long prime[MAXN], phi[MAXN], mu[MAXN];
bool not_prime[MAXN];
int tot;

inline void Linear_Shaker(int n)
{
	phi[1] = 1LL;
	mu[1] = 1LL;
	for (int i = 2; i <= n; i++)
	{
		if (!not_prime[i])
		{
			prime[++tot] = i;
			phi[i] = i - 1;
			mu[i] = -1;
		}
		for (int j = 1; i * prime[j] <= n; j++)
		{
			not_prime[i * prime[j]] = true;
			if (!(i % prime[j]))
			{
				mu[i * prime[j]] = 0LL;
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			mu[i * prime[j]] = -mu[i];
			phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
	return ;
}

/*
    By using BSGS(a,b,c),you can get the minimum solution of the equation:
    a^x==b (mod c)
*/
#define HMOD 1000007LL
struct hash_link
{
	long long ori;
	long long val;
	int nxt;
};

hash_link e[HMOD << 2];
int edge_num[HMOD], cnt;

inline void add(long long x, long long y)
{
	long long ori = x;
	x %= HMOD;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
		if (e[i].ori == ori) return ;
	e[cnt] = (hash_link)
	{
		ori, y, edge_num[x]
	};
	edge_num[x] = cnt++;
	return ;
}

inline long long query(long long x)
{
	long long ori = x;
	x %= HMOD;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
		if (e[i].ori == ori) return e[i].val;
	return -1LL;
}

long long exBSGS(long long a, long long b, long long MOD)
{
	memset(edge_num, -1, sizeof edge_num);
	cnt = 0;
	long long M = ceil(sqrt(MOD));
	long long t = 1LL, r = 1LL, x, y;
	for (long long i = 0; i < M; i++, t = t * a % MOD) add(t, i);
	for (long long i = 0; i <= M; i++, r = r * t % MOD)
	{
		exgcd(r, MOD, x, y);
		x = (x * b % MOD + MOD) % MOD;
		int res = query(x);
		if (res != -1) return i * M + res;
	}
	return -1LL;
}

/*
    By using Gauss_Elimination(n),you can solve n equation group.
    equation[1..n] is the coefficient and equation[n+1] is constant term.
    To the i_st equation,the formular is like:
    equation[i][1]x1+equation[i][2]x2+...+equation[i][n]xn=equation[i][n+1]
*/
double equations[MAXN][MAXN];
inline void Gauss_Elimination(int n)
{
	for (int i = 1; i <= n; i++)
	{
		int now = i;
		for (int j = i + 1; j <= n; j++)
			if (fabs(equations[now][i]) < fabs(equations[j][i])) now = j;
		swap(equations[now], equations[i]);
		double t = equations[i][i];
		for (int j = 1; j <= n + 1; j++) equations[i][j] /= t;
		for (int j = 1; j <= n; j++)
			if (j != i)
			{
				t = equations[j][i];
				for (int k = 1; k <= n + 1; k++)
					equations[j][k] -= t * equations[i][k];
			}
	}
	return ;
}

//By using KSM(a,b,MOD),you can figure out a^b%MOD.
long long KSM(long long a, long long b, long long MOD)
{
	long long res = 1, base = a;
	while (b)
	{
		if (b & 1) res = (res * base) % MOD;
		base = (base * base) % MOD;
		b >>= 1;
	}
	return res % MOD;
}

//By using Get_Factor_and_Inv(n,MOD),you can get i! and i^(-1) and i^(-1)!.
long long fac[MAXN], inv[MAXN], invfac[MAXN];
inline void Get_Factor_and_Inv(int n, long long MOD)
{
	inv[1] = fac[1] = invfac[0] = invfac[1] = 1LL;
	for (int i = 2; i <= n; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	for (int i = 2; i <= n; i++) fac[i] = (fac[i - 1] * i) % MOD, invfac[i] = (invfac[i - 1] * inv[i]) % MOD;
	return ;
}

inline long long A(int m, int n, long long MOD)
{
	return fac[n] * invfac[n - m] % MOD;
}
inline long long C(int m, int n, long long MOD)
{
	return fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}

/*
    By using Lucas_C(n,m,MOD),you can figure out C(m,n)%MOD as well.
    When n,m is huge but MOD is small than 1e8,Lucas_C is recommended.
*/
long long Lucas_C(long long m, long long n, long long MOD)
{
	if (n < m) return 0LL;
	if (n < MOD && m < MOD) return C(m, n, MOD);
	return Lucas_C(n / MOD, m / MOD, MOD) * Lucas_C(n % MOD, m % MOD, MOD) % MOD;
}

/*
    Some code about matrix.
    define the matrix has r rows and c columns.
*/
#define N 110
struct matrix
{
	int r, c;
	int m[N][N];
};

matrix fib, base, em;

matrix multiply(matrix a, matrix b, long long MOD)
{
	if (a.c != b.r) return em;
	matrix res;
	res.r = a.r;
	res.c = b.c;
	for (int i = 0; i < a.r; i++)
		for (int j = 0; j < b.c; j++)
		{
			res.m[i][j] = 0;
			for (int k = 0; k < a.c; k++)
				res.m[i][j] = (res.m[i][j] + a.m[i][k] * b.m[k][j]) % MOD;
		}
	return res;
}

/*
    By using get_Fibonacci(n,MOD),you can get the nth term of Fibonacci.
    define F[0]=1,F[1]=1,F[2]=2......
*/
long long get_Fibonacci(int n, long long MOD)
{
	fib.r = fib.c = base.r = base.c = 2LL;
	fib.m[0][0] = fib.m[0][1] = fib.m[1][0] = 1LL;
	fib.m[1][1] = 0LL;
	base.m[0][0] = base.m[0][1] = base.m[1][0] = 1LL;
	base.m[1][1] = 0LL;
	while (n)
	{
		if (n & 1) fib = multiply(fib, base, MOD);
		base = multiply(base, base, MOD);
		n >>= 1;
	}
	return fib.m[0][1];
}

int main()
{
	return 0;
}
