#include <bits/stdc++.h>
#define MAXN 4097
using namespace std;

int n, m, opt, a, b, c, d, k;
long long f[MAXN][MAXN];

inline int lowbit(int x)
{
	return x & -x;
}

inline void modify(int x, int y, long long v)
{
	for (int i = x; i <= n; i += lowbit(i))
		for (int j = y; j <= m; j += lowbit(j))
			f[i][j] += v;
	return ;
}

inline long long query(int x, int y)
{
	long long r = 0LL;
	for (int i = x; i; i -= lowbit(i))
		for (int j = y; j; j -= lowbit(j))
			r += f[i][j];
	return r;
}

inline void read(int &x)
{
	x = 0;
	char ch;
	bool f = false;
	if ((ch = getchar()) == EOF)
	{
		x = -1;
		return ;
	}
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		if ((ch = getchar()) == EOF)
		{
			x = -1;
			return ;
		}
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	if (f) x = -x;
	return ;
}

int main()
{
	read(n);
	read(m);
	while (true)
	{
		read(opt);
		if (!~opt) break;
		if (opt == 1)
		{
			read(a);
			read(b);
			read(k);
			modify(a, b, k);
		}
		else
		{
			read(a);
			read(b);
			read(c);
			read(d);
			printf("%lld\n", query(c, d) - query(c, b - 1) - query(a - 1, d) + query(a - 1, b - 1));
		}
	}
	return 0;
}