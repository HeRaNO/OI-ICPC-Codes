#include <stdio.h>
#include <string.h>
#define MAXN 1005

int T, n, p[MAXN][MAXN], a, b, c, d, opt;

inline int lowbit(int x)
{
	return x & -x;
}

inline void modify(int x, int y, int v)
{
	for (int i = x; i <= 1001; i += lowbit(i))
		for (int j = y; j <= 1001; j += lowbit(j))
			p[i][j] += v;
	return ;
}

inline int query(int x, int y)
{
	int r = 0;
	for (int i = x; i; i -= lowbit(i))
		for (int j = y; j; j -= lowbit(j))
			r += p[i][j];
	return r;
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
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(T);
	while (T--)
	{
		memset(p, 0, sizeof p);
		read(n);
		while (n--)
		{
			read(opt);
			if (!opt)
			{
				read(a);
				read(b);
				read(c);
				read(d);
				modify(a, b, 1);
				modify(c + 1, d + 1, 1);
				modify(c + 1, b, -1);
				modify(a, d + 1, -1);
			}
			else
			{
				read(a);
				read(b);
				printf("%d\n", query(a, b) & 1);
			}
		}
	}
	return 0;
}