#include <cstdio>
#define MAXN 2010
using namespace std;

int a[MAXN], ans[MAXN][MAXN];
int n, m, s, T, l, r;
long long x, y;

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
	read(s);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		--a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		x = 0;
		y = 0;
		for (int j = i; j <= n; j++)
		{
			m = a[j];
			ans[i][j] += ans[i][j - 1];
			if (m > 63)
			{
				if (!(y & (1LL << (m - 64))))
				{
					++ans[i][j];
					y |= (1LL << (m - 64));
				}
			}
			else
			{
				if (!(x & (1LL << m)))
				{
					++ans[i][j];
					x |= (1LL << m);
				}
			}
		}
	}
	read(T);
	while (T--)
	{
		read(l);
		read(r);
		printf("%d\n", ans[l][r]);
	}
	return 0;
}