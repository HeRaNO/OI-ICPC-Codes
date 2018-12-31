#include <cstdio>
#define MAXN 10010
using namespace std;

int n, T, x, l, r, opt, x1;
int c1[MAXN], c2[MAXN];

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
	for (int i = 1; i <= n; i++)
	{
		x1 = x;
		read(x);
		modify(c1, i, x - x1);
		modify(c2, i, (i - 1) * (x - x1));
	}
	while (T--)
	{
		read(opt);
		if (!opt)
		{
			read(l);
			read(r);
			read(x);
			modify(c1, l, x);
			modify(c1, r + 1, -x);
			modify(c2, l, x * (l - 1));
			modify(c2, r + 1, -x * r);
		}
		else
		{
			read(l);
			read(r);
			x = (l - 1) * query(c1, l - 1) - query(c2, l - 1);
			x1 = r * query(c1, r) - query(c2, r);
			printf("%d\n", x1 - x);
		}
	}
	return 0;
}
