#include <cmath>
#include <cstdio>
#include <cstring>
#define MAXN 210
#define MAXW 100010
using namespace std;

int a[MAXN], b[MAXN], c[MAXN];
int d[MAXN], e[MAXN], f[MAXN];
int v[MAXN], w[MAXN];
int dp1[MAXW], dp2[MAXW];
int n, m, p;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void dp1it()
{
	memset(dp1, 0x7f, sizeof dp1);
	dp1[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0, sum = 0, lim = (int)log2(c[i]);
		for (int j = 0; j < lim; j++)
		{
			v[++cnt] = a[i] * (1 << j);
			w[cnt] = b[i] * (1 << j);
			sum += (1 << j);
		}
		if (sum != c[i])
		{
			v[++cnt] = a[i] * (c[i] - sum);
			w[cnt] = b[i] * (c[i] - sum);
		}
		for (int k = 1; k <= cnt; k++)
		{
			for (int j = MAXW - 1; j >= v[k]; j--) dp1[j] = mymin(dp1[j], dp1[j - v[k]] + w[k]);
			for (int j = v[k] - 1; ~j; j--) dp1[j] = mymin(dp1[j], w[k]);
		}
	}
	return ;
}

inline void dp2it()
{
	for (int i = 1; i <= m; i++)
	{
		int cnt = 0, sum = 0, lim = (int)log2(f[i]);
		for (int j = 0; j < lim; j++)
		{
			v[++cnt] = d[i] * (1 << j);
			w[cnt] = e[i] * (1 << j);
			sum += (1 << j);
		}
		if (sum != f[i])
		{
			v[++cnt] = d[i] * (f[i] - sum);
			w[cnt] = e[i] * (f[i] - sum);
		}
		for (int k = 1; k <= cnt; k++)
			for (int j = MAXW - 1; j >= w[k]; j--)
				dp2[j] = mymax(dp2[j], dp2[j - w[k]] + v[k]);
	}
	return ;
}

int main()
{
	//freopen("food.in","r",stdin);freopen("food.out","w",stdout);
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 1; i <= n; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);
	for (int i = 1; i <= m; i++) scanf("%d %d %d", &d[i], &e[i], &f[i]);
	dp1it();
	dp2it();
	for (int i = 0; i < MAXW; i++)
		if (dp2[i] >= dp1[p])
		{
			printf("%d\n", i);
			return 0;
		}
	puts("-1");
	return 0;
}
