#include <cmath>
#include <cstdio>
#define MAXN 1000010
#define MAXB 1010
//If n is more than 1e6,Block is not recommended.
using namespace std;

int n, m, T, opt, l, r, v, block_num;
int a[MAXN], pos[MAXN];
int sum[MAXB], delta[MAXB], xi[MAXB];
bool isset[MAXB];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void clean(int x)
{
	sum[x] = delta[x] = xi[x] = 0;
	isset[x] = false;
	int l = (x - 1) * block_num + 1, r = mymin(x * block_num, n);
	for (int i = l; i <= r; i++) sum[x] += a[i];
	return ;
}

inline void Apply_delta(int x)
{
	int l = (x - 1) * block_num + 1, r = mymin(x * block_num, n);
	for (int i = l; i <= r; i++) a[i] += delta[x];
	delta[x] = 0;
	return ;
}

inline void Apply_xi(int x)
{
	int l = (x - 1) * block_num + 1, r = mymin(x * block_num, n);
	for (int i = l; i <= r; i++) a[i] = xi[x];
	xi[x] = 0;
	isset[x] = false;
	return ;
}

inline void Apply(int x)
{
	if (isset[x]) Apply_xi(x);
	if (delta[x]) Apply_delta(x);
	return ;
}

inline void modify_one(int x, int v)
{
	Apply(pos[x]);
	sum[pos[x]] -= a[x];
	a[x] = v;
	sum[pos[x]] += a[x];
	return ;
}

inline void modify_interval(int l, int r, int v)
{
	if (pos[l] == pos[r])
	{
		Apply(pos[l]);
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
		int p = (i - 1) * block_num + 1, q = mymin(i * block_num, n);
		sum[i] += (q - p + 1) * v;
	}
	return ;
}

inline void set_the_interval(int l, int r, int v)
{
	if (pos[l] == pos[r])
	{
		Apply(pos[l]);
		for (int i = l; i <= r; i++) sum[pos[l]] = sum[pos[l]] - a[i] + v, a[i] = v;
		return ;
	}
	Apply(pos[l]);
	Apply(pos[r]);
	for (int i = l; i <= pos[l]*block_num; i++) sum[pos[l]] = sum[pos[l]] - a[i] + v, a[i] = v;
	for (int i = (pos[r] - 1) * block_num + 1; i <= r; i++) sum[pos[r]] = sum[pos[r]] - a[i] + v, a[i] = v;
	for (int i = pos[l] + 1; i < pos[r]; i++)
	{
		xi[i] = v;
		isset[i] = true;
		delta[i] = 0;
		int p = (i - 1) * block_num + 1, q = mymin(i * block_num, n);
		sum[i] = (q - p + 1) * v;
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

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	read(n);
	block_num = (int)sqrt(n);
	m = n / block_num;
	if (n % block_num) m++;
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		pos[i] = (i - 1) / block_num + 1;
	}
	for (int i = 1; i <= m; i++) clean(i);
	read(T);
	while (T--)
	{
		read(opt);
		if (opt == 0)
		{
			read(l);
			read(v);
			modify_one(l, v);
		}
		else if (opt == 1)
		{
			read(l);
			read(r);
			read(v);
			modify_interval(l, r, v);
		}
		else if (opt == 2)
		{
			read(l);
			read(r);
			read(v);
			set_the_interval(l, r, v);
		}
		else
		{
			read(l);
			read(r);
			printf("%d\n", query(l, r));
		}
	}
	return 0;
}
