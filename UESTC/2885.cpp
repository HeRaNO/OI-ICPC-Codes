#include <cstdio>
#include <algorithm>
#define MAXK 105
#define MAXN 200005

const int M = 998244353;

struct Matrix
{
	int m[MAXK][MAXK];
};

bool vis[MAXK];
int a[MAXK], b[MAXK];
int fac[MAXN], inv[MAXN], invfac[MAXN];

int fadd(int x, int y){ x += y; if (x >= M) x -= M; return x; }
int fsub(int x, int y){ x -= y; if (x <  0) x += M; return x; }
int fmul(int x, int y){ return 1LL * x * y % M; }

int fpow(int a, int b)
{
	int r = 1;
	for (; b; b >>= 1, a = fmul(a, a))
		if (b & 1) r = fmul(r, a);
	return r;
}

int finv(int a){ return fpow(a, M - 2); }

int getDet(Matrix &a, int n)
{
	int det = 1;
	for (int i = 1; i <= n; i++)
	{
		int now = 0;
		for (int j = 1; j <= n && !now; j++) if (!vis[j] && a.m[j][i]) now = j;
		if (!now) continue;
		if (now != i) det = -det;
		vis[i] = true;
		for (int j = 1; j <= n; j++)
			std::swap(a.m[now][j], a.m[i][j]);
		int t = finv(a.m[i][i]);
		for (int j = 1; j <= n; j++)
			if (j != i)
			{
				int x = fmul(a.m[j][i], t);
				for (int k = 1; k <= n; k++) 
					a.m[j][k] = fsub(a.m[j][k], fmul(x, a.m[i][k]));
			}
	}
	if (det == -1)
		det = M - 1;
	for (int i = 1; i <= n; i++)
		det = fmul(det, a.m[i][i]);
	return det;
}

void init(int n)
{
	fac[0] = inv[1] = invfac[0] = 1;
	for (int i = 2; i <= n; i++)
		inv[i] = fmul(M - M / i, inv[M % i]);
	for (int i = 1; i <= n; i++)
		fac[i] = fmul(fac[i - 1], i),
		invfac[i] = fmul(invfac[i - 1], inv[i]);
	return ;
}

int C(int n, int m){ return fmul(fac[n], fmul(invfac[m], invfac[n - m])); }

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	init(n << 1);
	for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= k; i++) scanf("%d", &b[i]);
	Matrix A;
	for (int i = 1; i <= k; i++)
		for (int j = k; j; j--)
		{
			if (b[j] < a[i]) break;
			A.m[i][j] = C(n - 1 + b[j] - a[i], n - 1);
		}
	printf("%d\n", getDet(A, k));
	return 0;
}