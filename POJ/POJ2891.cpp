#include <cstdio>
#define MAXN 100010

long long a1, m1, a2, m2, g, c, x, y, t;
long long m[MAXN], a[MAXN];
int n;
bool no_solution;

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

int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++) scanf("%lld %lld", &m[i], &a[i]);
		printf("%lld\n", exCRT(n));
		/*  no_solution=false;
		    scanf("%lld %lld",&m1,&a1);
		    for (int i=1;i<n;i++)
		    {
		    scanf("%lld %lld",&m2,&a2);
		    if (no_solution) continue;
		    g=exgcd(m1,m2,x,y);
		    c=a2-a1;
		    if (c%g) {no_solution=true;continue;}
		    t=m2/g;
		    x=(x*c/g%t+t)%t;
		    a1=m1*x+a1;
		    m1=m1*m2/g;
		    }
		    if (no_solution) a1=-1;
		    printf("%lld\n",a1);*/
	}
	return 0;
}
