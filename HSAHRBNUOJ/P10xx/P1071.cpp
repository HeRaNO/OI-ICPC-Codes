#include <cstdio>
#define MAXN 100010
using namespace std;

int n, T, x, l, r, opt, x1;
int c[MAXN];

inline int lowbit(int x)
{
	return x & -x;
}

inline void modify(int c[], int x, int delta)
{
	for (; x <= n; x += lowbit(x)) c[x] += delta;
	return ;
}

inline int query(int c[], int x)
{
	int res = 0;
	for (; x; x -= lowbit(x)) res += c[x];
	return res;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'm')
		{
			x = 0;
			return ;
		}
		if (ch == 'q')
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
	for (int i = 1; i <= n; i++) read(x), modify(c, i, x);
	while (T--)
	{
		read(opt);
		if (!opt)
		{
			read(l);
			read(x);
			x1 = query(c, l) - query(c, l - 1);
			modify(c, l, x - x1);
		}
		else
		{
			read(l);
			read(r);
			printf("%d\n", query(c, r) - query(c, l - 1));
		}
	}
	return 0;
}
