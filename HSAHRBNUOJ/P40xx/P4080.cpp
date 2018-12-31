#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 1000010
using namespace std;

int n, m, T, block, opt, l, r, x;
int a[MAXN], b[MAXN], delta[MAXN], pos[MAXN];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

void clean(int x)
{
	int l = (x - 1) * block + 1, r = mymin(x * block, n);
	for (int i = l; i <= r; i++) b[i] = a[i];
	sort(b + l, b + r + 1);
	return ;
}

int binary(int x, int k)
{
	int l = (x - 1) * block + 1, r = mymin(x * block, n), last = r, mid;
	while (l <= r)
	{
		mid = l + r >> 1;
		if (b[mid] < k) l = mid + 1;
		else r = mid - 1;
	}
	return last - l + 1;
}

void modify(int l, int r, int k)
{
	if (pos[l] == pos[r])
	{
		for (int i = l; i <= r; i++) a[i] += k;
		return ;
	}
	for (int i = l; i <= pos[l]*block; i++) a[i] += k;
	for (int i = (pos[r] - 1) * block + 1; i <= r; i++) a[i] += k;
	clean(pos[l]);
	clean(pos[r]);
	for (int i = pos[l] + 1; i < pos[r]; i++) delta[i] += k;
	return ;
}

int query(int l, int r, int k)
{
	int res = 0;
	if (pos[l] == pos[r])
	{
		for (int i = l; i <= r; i++) if (a[i] + delta[pos[i]] >= k) res++;
		return res;
	}
	for (int i = l; i <= pos[l]*block; i++) if (a[i] + delta[pos[i]] >= k) res++;
	for (int i = (pos[r] - 1) * block + 1; i <= r; i++) if (a[i] + delta[pos[i]] >= k) res++;
	for (int i = pos[l] + 1; i < pos[r]; i++) res += binary(i, k - delta[i]);
	return res;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'A')
		{
			x = 0;
			return ;
		}
		if (ch == 'M')
		{
			x = 1;
			return ;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	read(T);
	block = (int)sqrt(n);
	if (n % block) m = n / block + 1;
	else m = n / block;
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		pos[i] = (i - 1) / block + 1;
	}
	for (int i = 1; i <= m; i++) clean(i);
	while (T--)
	{
		read(opt);
		read(l);
		read(r);
		read(x);
		if (opt) modify(l, r, x);
		else printf("%d\n", query(l, r, x));
	}
	return 0;
}
