#include <cstdio>
#define MAXN 200010
using namespace std;

int f[MAXN], ans, n, x;

inline int binary(int x)
{
	int l = 1, r = ans, m, p;
	while (l <= r)
	{
		m = l + r >> 1;
		if (f[m] < x) l = m + 1;
		else r = m - 1;
	}
	return l;
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
	f[0] = 1 << 31;
	for (int i = 1; i <= n; i++)
	{
		read(x);
		if (x > f[ans]) f[++ans] = x;
		else f[binary(x)] = x;
	}
	printf("%d\n", ans);
	return 0;
}
