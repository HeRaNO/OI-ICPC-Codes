#include <cstdio>
#define MOD 7

struct matrix
{
	int m[2][2];
};

matrix ans, base;
int a, b, n;

matrix multiply(matrix a, matrix b)
{
	matrix res;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			res.m[i][j] = 0;
			for (int k = 0; k < 2; k++)
				res.m[i][j] += (a.m[i][k] * b.m[k][j]) % MOD;
		}
	return res;
}

void work(int k)
{
	base.m[0][0] = a;
	base.m[0][1] = 1;
	base.m[1][0] = b;
	base.m[1][1] = 0;
	ans.m[0][0] = a + b;
	ans.m[0][1] = 1;
	ans.m[1][0] = 1;
	ans.m[1][1] = 1;
	while (k)
	{
		if (k & 1) ans = multiply(ans, base);
		base = multiply(base, base);
		k = k >> 1;
	}
	return ;
}

int main()
{
	scanf("%d %d %d", &a, &b, &n);
	if (n < 3) printf("1\n");
	else
	{
		work(n - 3);
		printf("%d\n", (ans.m[0][0]) % MOD);
	}
	return 0;
}
