#include <cstdio>
#define MAXN 241

int n, m, T, x, y, p, q, ans;
bool a[MAXN][MAXN];

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
	read(T);
	while (T--)
	{
		read(x);
		read(y);
		read(p);
		read(q);
		for (int i = x; i <= p; i++)
			for (int j = y; j <= q; j++)
				a[i][j] = true;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j]) ++ans;
	printf("%d\n", ans);
	return 0;
}