#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 50010
using namespace std;

int n, Case, T, block_num, m;
int a[MAXN], b[MAXN], pos[MAXN];
int x, y, v, opt;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void clean(int x)
{
	int l = (x - 1) * block_num + 1, r = mymin(x * block_num, n);
	for (int i = l; i <= r; i++) b[i] = a[i];
	sort(b + l, b + r + 1);
	return ;
}

inline int Binary(int l, int r, int x)
{
	int ans = r + 1, mid;
	while (l <= r)
	{
		mid = l + r >> 1;
		if (x <= b[mid]) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}

inline void modify(int x, int v)
{
	a[x] = v;
	clean(pos[x]);
	return ;
}

inline int get_count(int l, int r, int k)
{
	int sum = 0, p, q;
	if (pos[l] == pos[r])
	{
		for (int i = l; i <= r; i++) if (a[i] < k) sum++;
		return sum;
	}
	for (int i = l; i <= pos[l]*block_num; i++) if (a[i] < k) sum++;
	for (int i = (pos[r] - 1) * block_num + 1; i <= r; i++) if (a[i] < k) sum++;
	for (int i = pos[l] + 1; i < pos[r]; i++)
	{
		p = (i - 1) * block_num + 1, q = mymin(i * block_num, n);
		sum += Binary(p, q, k) - p;
	}
	return sum;
}

inline int query(int x, int y, int k)
{
	int l = 0, r = 1e9 + 1, mid, ans;
	while (l <= r)
	{
		mid = l + r >> 1;
		if (get_count(x, y, mid) < k) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'C')
		{
			x = 0;
			return ;
		}
		if (ch == 'Q')
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
	read(T);
	while (T--)
	{
		read(n);
		read(Case);
		block_num = (int)sqrt(n);
		if (n % block_num) m = n / block_num + 1;
		else m = n / block_num;
		for (int i = 1; i <= n; i++)
		{
			read(a[i]);
			pos[i] = (i - 1) / block_num + 1;
		}
		for (int i = 1; i <= m; i++) clean(i);
		while (Case--)
		{
			read(opt);
			if (!opt)
			{
				read(x);
				read(v);
				modify(x, v);
			}
			else
			{
				read(x);
				read(y);
				read(v);
				printf("%d\n", query(x, y, v));
			}
		}
	}
	return 0;
}
