#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 300010
using namespace std;

int n, a[MAXN], cnt;
pair <int, int *> b[MAXN];
long long c[MAXN];
long long higher[MAXN], lower[MAXN], ans;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int lowbit(int x)
{
	return x & -x;
}

inline void add(int x)
{
	for (; x; x -= lowbit(x)) c[x]++;
	return ;
}

inline long long query(int x)
{
	long long r = 0;
	for (; x <= cnt; x += lowbit(x)) r += c[x];
	return r;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		b[i].first = a[i];
		b[i].second = &a[i];
	}
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (b[i].first != b[i - 1].first) cnt++;
		*b[i].second = cnt;
	}
	for (int i = 1; i <= n; i++)
	{
		add(a[i]);
		higher[i] = query(a[i] + 1);
	}
	memset(c, 0, sizeof c);
	for (int i = n; i; i--)
	{
		add(a[i]);
		lower[i] = query(a[i] + 1);
	}
	for (int i = 1; i <= n; i++) ans += mymin(higher[i], lower[i]);
	printf("%lld\n", ans);
	return 0;
}