#include <stdio.h>

const int M = 10000;

struct Matrix
{
	int a[2][2];
	Matrix operator * (const Matrix &m)const
	{
		Matrix c;
		c.a[0][0] = (a[0][0] * m.a[0][0] + a[0][1] * m.a[1][0]) % M;
		c.a[0][1] = (a[0][0] * m.a[0][1] + a[0][1] * m.a[1][1]) % M;
		c.a[1][0] = (a[1][0] * m.a[0][0] + a[1][1] * m.a[1][0]) % M;
		c.a[1][1] = (a[1][0] * m.a[0][1] + a[1][1] * m.a[1][1]) % M;
		return c;
	}
};

Matrix f, r;

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n != -1)
	{
		--n;
		f.a[0][0] = f.a[0][1] = f.a[1][0] = 1;
		f.a[1][1] = 0;
		r.a[0][0] = r.a[0][1] = r.a[1][0] = 1;
		r.a[1][1] = 0;
		if (n < 0)
		{
			puts("1");
			continue;
		}
		for (; n; f = f * f, n >>= 1) if (n & 1) r = r * f;
		printf("%d\n", r.a[0][1]);
	}
	return 0;
}