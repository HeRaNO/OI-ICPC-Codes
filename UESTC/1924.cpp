#include <stdio.h>
#define MAXN 100010

int n, m, T, a, b;
int f[MAXN], siz[MAXN];

inline int getf(int x)
{
	return x == f[x] ? x : f[x] = getf(f[x]);
}

inline void merge(int x, int y)
{
	x = getf(x);
	y = getf(y);
	if (x == y) return ;
	if (siz[x] > siz[y])
	{
		f[y] = x;
		siz[x] += siz[y];
	}
	else
	{
		f[x] = y;
		siz[y] += siz[x];
	}
	return ;
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
	read(m);
	for (int i = 1; i <= n; i++) f[i] = i, siz[i] = 1;
	for (int i = 1; i <= m; i++)
	{
		read(a);
		read(b);
		merge(a, b);
	}
	read(T);
	while (T--)
	{
		read(a);
		printf("%d\n", siz[getf(a)]);
	}
	return 0;
}