#include <cstdio>
#define MAXN 100010

int n, T, opt, a, b, c[MAXN];

inline int lowbit(int x)
{
	return x & -x;
}

inline void modify(int x, int v)
{
	for (; x <= n; x += lowbit(x)) c[x] += v;
	return ;
}

inline int query(int x)
{
	int r = 0;
	for (; x; x -= lowbit(x)) r += c[x];
	return r;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	read(T);
	while (T--)
	{
		read(opt);
		if (opt == 1)
		{
			read(a);
			read(b);
			modify(a, 1);
			modify(b + 1, -1);
		}
		else
		{
			read(a);
			printf("%d\n", query(a) & 1);
		}
	}
	return 0;
}