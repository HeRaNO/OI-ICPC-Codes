#include <cstdio>
#define MAXN 1000010
using namespace std;

long long c[MAXN], a[MAXN];
int n, T, opt, l, r, x, lx;

inline void modify(int x, int v)
{
	for (; x <= n + 1; x += x & -x) c[x] += v;
	return ;
}
inline long long query(int x)
{
	long long r = 0;
	for (; x; x -= x & -x) r += c[x];
	return r;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	bool f = false;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	if (f) x = -x;
	return ;
}

int main()
{
	read(n);
	read(T);
	for (int i = 1; i <= n; i++) read(x), a[i] = x;
	while (T--)
	{
		read(opt);
		if (opt == 1)
		{
			read(l);
			read(r);
			read(x);
			modify(l, x);
			modify(r + 1, -x);
		}
		else
		{
			read(x);
			printf("%lld\n", query(x) + a[x]);
		}
	}
	return 0;
}
