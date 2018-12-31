#include <cstdio>
#define MAXN 1000010
using namespace std;

long long c[MAXN];
int n, T, opt, l, r;

inline void modify(int x, int v)
{
	for (; x <= n; x += x & -x) c[x] += v;
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
	for (int i = 1; i <= n; i++)
	{
		read(l);
		modify(i, l);
	}
	while (T--)
	{
		read(opt);
		read(l);
		read(r);
		if (opt == 1) modify(l, r);
		else printf("%lld\n", query(r) - query(l - 1));
	}
	return 0;
}