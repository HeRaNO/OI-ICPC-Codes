#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 110
using namespace std;

struct matrix
{
	long long m[MAXN][MAXN];
	void clean()
	{
		memset(m, 0, sizeof m);
	}
	void unit()
	{
		memset(m, 0, sizeof m);
		for (int i = 0; i < MAXN; i++) m[i][i] = 1LL;
	}
};

matrix a, ans;
int n, m, k, x, y, opt;

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'g') return ;
		if (ch == 'e')
		{
			x = 1;
			return ;
		}
		if (ch == 's')
		{
			x = 2;
			return ;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

matrix multiply(matrix a, matrix b)
{
	matrix res;
	res.clean();
	for (int i = 0; i <= n; i++)
		for (int k = 0; k <= n; k++)
			if (a.m[i][k])
			{
				for (int j = 0; j <= n; j++) res.m[i][j] += a.m[i][k] * b.m[k][j];
			}
	return res;
}

inline matrix KSM(matrix a, int k)
{
	matrix res;
	res.unit();
	while (k)
	{
		if (k & 1) res = multiply(res, a);
		a = multiply(a, a);
		k >>= 1;
	}
	return res;
}

int main()
{
	//while (true)
	//{
	read(n);
	read(m);
	read(k);
	//if (!n&&!m&&!k) break;
	a.unit();
	for (int i = 1; i <= k; i++)
	{
		read(opt);
		if (!opt)
		{
			read(x);
			a.m[0][x]++;
		}
		else if (opt == 1)
		{
			read(x);
			for (int i = 0; i <= n; i++) a.m[i][x] = 0;
		}
		else
		{
			read(x);
			read(y);
			for (int i = 0; i <= n; i++) swap(a.m[i][x], a.m[i][y]);
		}
	}
	ans = KSM(a, m);
	printf("%lld", ans.m[0][1]);
	for (int i = 2; i <= n; i++) printf(" %lld", ans.m[0][i]);
	puts("");
	//}
	return 0;
}
