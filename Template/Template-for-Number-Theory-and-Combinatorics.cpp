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
	long long res = exgcd(b, a % b, y, x);
	y -= (a / b) * x;
	return res;
}

//Get a^{-1} (mod m)
inline long long inv(long long a, long long m)
{
	long long x, y;
	exgcd(a, m, x, y);
	return (x + m) % m;
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

unordered_map <long long, long long> mp;

long long exBSGS(long long a, long long b, long long M)
{
	if (b == 1) return 0;
	long long w = 1; int c = 0;
	for (long long d; (d = gcd(a, M)) != 1;)
	{
		if (b % d) return -1;
		b /= d; M /= d; ++c; w = w * (a / d) % M;
		if (w == b) return c;
	}
	b = b * inv(w, M) % M; mp.clear();
	long long t = 1LL, r = b, x, y, B = ceil(sqrt(M));
	for (long long i = 0; i < B; i++, t = t * a % M) if (!mp.count(t)) mp.insert({t, i});
	t = inv(t, M);
	for (long long i = 0; i < B; i++, b = b * t % M) if (mp.count(b)) return i * B + mp[b] + c;
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

struct Matrix
{
	long long m[MAXN][MAXN];
}inv;

bool vis[MAXN];
long long det;
int rnk;

inline void getDetRankInv(Matrix a)
{
	memset(vis, 0, sizeof vis);
	det = 1; rnk = n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			inv.m[i][j] = i == j;
	for (int i = 1; i <= n; i++)
	{
		int now = 0;
		for (int j = 1; j <= n && !now; j++) if (!vis[j] && a.m[j][i]) now = j;
		if (!now){ --rnk; continue; }
		if (now != i) det = -det;
		vis[i] = true;
		for (int j = 1; j <= n; j++)
		{
			swap(a.m[now][j], a.m[i][j]);
			swap(inv.m[now][j], inv.m[i][j]);
		}
		long long t = inv(a.m[i][i], M);
		for (int j = 1; j <= n; j++)
			if (j != i)
			{
				long long x = a.m[j][i] * t % M;
				for (int k = 1; k <= n; k++) 
				{
					a.m[j][k] -= x * a.m[i][k] % M; (a.m[j][k] += M) %= M;
					inv.m[j][k] -= x * inv.m[i][k]%M; (inv.m[j][k] += M) %= M;
				}
			}
	}
	det = (det + M) % M;
	for (int i = 1; i <= n; i++)
	{
		(det *= a.m[i][i]) %= M;
		long long t = inv(a.m[i][i], M);
		for (int j = 1; j <= n; j++) (inv.m[i][j] *= t) %= M;
	}
	return ;
}

inline Matrix Gauss_Elimination(Matrix a)
{
	memset(vis, false, sizeof vis);
	for (int i = 1; i <= n; i++)
	{
		int now = 0;
		for (int j = 1; j <= n && !now; j++) if (!vis[j] && a.m[j][i]) now = j;
		if (!now) continue;
		vis[i] = true;
		for (int j = 1; j <= n; j++) swap(a.m[now][j], a.m[i][j]);
		long long t = inv(a.m[i][i], M);
		for (int j = 1; j <= n; j++)
			if (j != i)
			{
				long long x = a.m[j][i] * t % M;
				for (int k = 1; k <= n; k++) a.m[j][k] -= x * a.m[i][k] % M, (a.m[j][k] += M) %= M;
			}
	}
	return a;
}

//By using Get_Factor_and_Inv(n,MOD),you can get i! and i^(-1) and i^(-1)!.
long long fac[MAXN], inv[MAXN], invfac[MAXN];
inline void Get_Factor_and_Inv(int n, long long MOD)
{
	inv[1] = fac[0] = invfac[0] = 1LL;
	for (int i = 2; i <= n; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % MOD, invfac[i] = (invfac[i - 1] * inv[i]) % MOD;
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
    When n,m is huge but MOD is smaller than 1e8,Lucas_C is recommended.
*/
long long Lucas_C(long long m, long long n, long long MOD)
{
	if (n < m) return 0LL;
	if (n < MOD && m < MOD) return C(m, n, MOD);
	return Lucas_C(n / MOD, m / MOD, MOD) * Lucas_C(n % MOD, m % MOD, MOD) % MOD;
}

int main()
{
	return 0;
}
