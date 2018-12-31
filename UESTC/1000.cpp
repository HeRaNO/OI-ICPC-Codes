#include <stdio.h>

const long long M = 1e9;

struct Matrix
{
	long long a[2][2];
	Matrix operator * (const Matrix &m)const
	{
		Matrix c;
		c.a[0][0] = (a[0][0] * m.a[0][0] % M + a[0][1] * m.a[1][0] % M) % M;
		c.a[0][1] = (a[0][0] * m.a[0][1] % M + a[0][1] * m.a[1][1] % M) % M;
		c.a[1][0] = (a[1][0] * m.a[0][0] % M + a[1][1] * m.a[1][0] % M) % M;
		c.a[1][1] = (a[1][0] * m.a[0][1] % M + a[1][1] * m.a[1][1] % M) % M;
		return c;
	}
};

Matrix f, r;

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		--n;
		f.a[0][0] = f.a[0][1] = f.a[1][0] = 1LL;
		f.a[1][1] = 0;
		r.a[0][0] = r.a[0][1] = r.a[1][0] = 1LL;
		r.a[1][1] = 0;
		if (n < 0)
		{
			puts("000000001");
			continue;
		}
		for (; n; f = f * f, n >>= 1) if (n & 1) r = r * f;
		printf("%09lld\n", r.a[0][0]);
	}
	return 0;
}