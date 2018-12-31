#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;

struct Point
{
	int x, y;
	bool operator < (const Point &a)const
	{
		return y == a.y ? x < a.x : y < a.y;
	}
};

Point a[MAXN];
int ans[MAXN], c[MAXN], n, r, m;

inline int lowbit(int x)
{
	return x & -x;
}
inline void max(int &a, int b)
{
	if (a < b) a = b;
	return ;
}
inline int query(int x)
{
	int r = 0;
	for (; x; x -= lowbit(x)) r += c[x];
	return r;
}
inline void modify(int x)
{
	for (; x <= m; x += lowbit(x)) ++c[x];
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
	for (int i = 1; i <= n; i++)
	{
		read(a[i].x);
		read(a[i].y);
		max(m, a[i].x);
	}
	sort(a + 1, a + n + 1);
	++m;
	for (int i = 1; i <= n; i++)
	{
		++a[i].x;
		++ans[query(a[i].x)];
		modify(a[i].x);
	}
	for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
	return 0;
}