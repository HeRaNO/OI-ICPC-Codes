#include <bits/stdc++.h>
using namespace std;

const long long M=1125899839733759LL;

#define N 2
struct matrix
{
	int r, c;
	long long m[N][N];
};

matrix fib, base, em;

inline long long fmul(long long a,long long b,long long p)
{
	long long r=0;
	for (;b;b>>=1,a=(a+a)%p) if (b&1) r=(r+a)%p;
	return r;
}

inline long long fpow(long long a,long long b,long long p)
{
	long long r=1;
	for (;b;b>>=1,a=fmul(a,a,p)%p) if (b&1) r=fmul(r,a,p)%p;
	return r; 
}

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
				res.m[i][j] = (res.m[i][j] + fmul(a.m[i][k] , b.m[k][j], MOD)) % MOD;
		}
	return res;
}

long long get_Fibonacci(long long n, long long MOD)
{
	if (!~n) return 0;
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
	return fib.m[0][1]%MOD;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		long long n;
		scanf("%lld",&n);
		printf("%lld\n",get_Fibonacci((fpow(2,n,M-1)-1+M-1)%(M-1),M));
	}
	return 0;
}