#include <cmath>
#include <cstdio>
#define MAXN 10010
#define MAXB 110
using namespace std;

int n, m, T, block_num, u, v, k;
int a[MAXN], pos[MAXN];
int sum[MAXB], delta[MAXB];
char opt[10];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void clean(int x)
{
	sum[x] = 0;
	int l = (x - 1) * block_num + 1, r = mymin(x * block_num, n);
	for (int i = l; i <= r; i++) sum[x] += a[i];
	return ;
}

void Apply(int x)
{
	if (!delta[x]) return ;
	int l = (x - 1) * block_num + 1, r = mymin(x * block_num, n);
	for (int i = l; i <= r; i++) a[i] += delta[x];
	delta[x] = 0;
	return ;
}

inline void modify(int l, int r, int v)
{
	if (pos[l] == pos[r])
	{
		if (delta[pos[l]]) Apply(pos[l]);
		for (int i = l; i <= r; i++) a[i] += v;
		sum[pos[l]] += (r - l + 1) * v;
		return ;
	}
	Apply(pos[l]);
	Apply(pos[r]);
	for (int i = l; i <= pos[l]*block_num; i++) a[i] += v, sum[pos[l]] += v;
	for (int i = (pos[r] - 1) * block_num + 1; i <= r; i++) a[i] += v, sum[pos[r]] += v;
	for (int i = pos[l] + 1; i < pos[r]; i++)
	{
		delta[i] += v;
		int l = (i - 1) * block_num + 1, r = mymin(i * block_num, n);
		sum[i] += (r - l + 1) * v;
	}
	return ;
}

inline int query(int l, int r)
{
	int res = 0;
	if (pos[l] == pos[r])
	{
		Apply(pos[l]);
		for (int i = l; i <= r; i++) res += a[i];
		return res;
	}
	Apply(pos[l]);
	Apply(pos[r]);
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
		scanf("%s", opt);
		if (opt[0] == 'm')
		{
			scanf("%d %d %d", &u, &v, &k);
			modify(u, v, k);
		}
		else
		{
			scanf("%d %d", &u, &v);
			printf("%d\n", query(u, v));
		}
	}
	return 0;
}
