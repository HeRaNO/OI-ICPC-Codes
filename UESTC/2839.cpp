#include <cstdio>
#define MAXN 105

const int M = 1'000'000'007;

int fac[MAXN];

void init(int n)
{
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % M;
	return ;
}

int fpow(int a, int b)
{
	int r = 1;
	for (; b; b >>= 1, a = 1LL * a * a % M)
		if (b & 1) r = 1LL * r * a % M;
	return r;
}

void fadd(int &x, int y){ x += y; if (x >= M) x -= M; return ; }

int calc1(int n)
{
	if (!n) return 1;
	return 1LL * fac[n] * fpow(2, (n - 1) * (n - 2) / 2) % M;
}

int calc2(int n)
{
	int ans = 0;
	for (int i = 0; i <= n - 2; i++)
	{
		int j = n - 2 - i;
		int m = n - 4 + (!i) + (!j);
		fadd(ans,
			((i && j) ? 2LL : 1LL) * (n * (n - 1) / 2) % M *
			fpow(2, m * 2) % M * calc1(n - 2) % M);
	}
	return ans;
}

int calc3(int n)
{
	int ans = 0;
	for (int i = 0; i <= n - 3; i++)
	{
		int j = n - 3 - i;
		int m = (i != 0) + (j != 0) + (i != 0 && j != 0);
		if (i) m += 3 * (i - 1);
		if (j) m += 3 * (j - 1);
		fadd(ans,
			1LL * n * (n - 1) * (n - 2) * fpow(2, m) % M
			* calc1(n - 3) % M);
	}
	return ans;
}

int main()
{
	int n;
	scanf("%d", &n);
	init(n);
	printf("%d\n%d\n%d\n", calc1(n), calc2(n), calc3(n));
	return 0;
}