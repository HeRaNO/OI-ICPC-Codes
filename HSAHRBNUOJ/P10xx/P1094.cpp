#include <cstdio>
#define MAXN 100010
using namespace std;

int n, a[MAXN];
long long c[MAXN], ans;

inline int lowbit(int x)
{
	return x & -x;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

void add(int x)
{
	for (; x <= MAXN; x += lowbit(x)) c[x]++;
	return ;
}

long long query(int x)
{
	long long res = 0;
	for (; x; x -= lowbit(x)) res += c[x];
	return res;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = n; i; i--)
	{
		ans += query(a[i] - 1);
		add(a[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
