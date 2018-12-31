#include <cstdio>
using namespace std;

struct matrix
{
	int m[2][2];
} ans, base;

int n, p, t;

matrix mul(matrix a, matrix b)
{
	matrix aans;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			aans.m[i][j] = 0;
			for (int k = 0; k < 2; k++)
				aans.m[i][j] = (aans.m[i][j] + a.m[i][k] * b.m[k][j]) % p;
		}
	return aans;
}

void fib(int k)
{
	base.m[0][0] = 1;
	base.m[0][1] = 1;
	base.m[1][0] = 1;
	base.m[1][1] = 0;
	ans.m[0][0] = 1;
	ans.m[1][1] = 1;
	ans.m[0][1] = 0;
	ans.m[1][0] = 0;
	while (k)
	{
		if (k & 1) ans = mul(ans, base);
		base = mul(base, base);
		k >>= 1;
	}
	printf("%d\n", ans.m[0][1]);
	return ;
}

int main()
{
	scanf("%d %d", &n, &p);
	while (n--)
	{
		scanf("%d", &t);
		fib(t + 2);
	}
	return 0;
}
