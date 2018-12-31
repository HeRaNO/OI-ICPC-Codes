#include <cstdio>
#define MAXN 10005
#define MAXA 5005
#define MAXK 505
using namespace std;

int c[MAXA + MAXK][MAXK];
int n, k, now, ans, mxa, a[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
inline int lowbit(int x)
{
	return x & -x;
}

inline void modify(int x, int y, int v)
{
	for (int i = x; i <= mxa + k; i += lowbit(i))
		for (int j = y; j <= k + 1; j += lowbit(j))
			c[i][j] = mymax(c[i][j], v);
	return ;
}

inline int query(int x, int y)
{
	int ans = 0;
	for (int i = x; i; i -= lowbit(i))
		for (int j = y; j; j -= lowbit(j))
			ans = mymax(ans, c[i][j]);
	return ans;
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
	read(k);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		mxa = mymax(mxa, a[i]);
	}
	for (int i = 1; i <= n; i++)
		for (int j = k; ~j; j--)
		{
			now = query(a[i] + j, j + 1) + 1;
			ans = mymax(now, ans);
			modify(a[i] + j, j + 1, now);
		}
	printf("%d\n", ans);
	return 0;
}