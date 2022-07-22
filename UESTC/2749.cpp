#include <cstdio>

int mod(long long a, int P){ return a < (P << 1) ? a : a % P + P; }

int fpow(int a, int b, int P)
{
	int r = 1;
	for (; b; b >>= 1, a = mod(1LL * a * a, P))
		if (b & 1) r = mod(1LL * r * a, P);
	return r;
}

int phi(int x)
{
	int res = x;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
		{
			res /= i;
			res *= (i - 1);
			while (x % i == 0) x /= i;
		}
	if (x != 1) res /= x, res *= (x - 1);
	return res;
}

int Solve(int a, int b, int P)
{
	if (b == 1 || P == 1) return mod(a, P);
	return fpow(a, Solve(a, b - 1, phi(P)), P);
}

int main()
{
	int a, b, m;
	scanf("%d %d %d", &a, &b, &m);
	printf("%d\n", Solve(a, b, m) % m);
	return 0;
}