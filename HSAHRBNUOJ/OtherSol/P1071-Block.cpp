#include <cmath>
#include <cstdio>
#define MAXN 10010
#define MAXB 110
using namespace std;

int n, m, T, block_num, u, v;
int a[MAXN], pos[MAXN];
int sum[MAXB];
char opt[10];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void clean(int x)
{
	int l = (x - 1) * block_num + 1, r = mymin(x * block_num, n);
	for (int i = l; i <= r; i++) sum[x] += a[i];
	return ;
}

inline void modify(int x, int v)
{
	sum[pos[x]] -= a[x];
	a[x] = v;
	sum[pos[x]] += a[x];
	return ;
}

inline int query(int l, int r)
{
	int res = 0;
	if (pos[l] == pos[r])
	{
		for (int i = l; i <= r; i++) res += a[i];
		return res;
	}
	for (int i = l; i <= pos[l]*block_num; i++) res += a[i];
	for (int i = (pos[r] - 1) * block_num + 1; i <= r; i++) res += a[i];
	for (int i = pos[l] + 1; i < pos[r]; i++) res += sum[i];
	return res;
}

int main()
{
	scanf("%d %d", &n, &T);
	block_num = (int)sqrt(n);
	m = n / block_num;
	if (n % block_num) m++;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pos[i] = (i - 1) / block_num + 1;
	}
	for (int i = 1; i <= m; i++) clean(i);
	while (T--)
	{
		scanf("%s %d %d", opt, &u, &v);
		if (opt[0] == 'm') modify(u, v);
		else printf("%d\n", query(u, v));
	}
	return 0;
}
