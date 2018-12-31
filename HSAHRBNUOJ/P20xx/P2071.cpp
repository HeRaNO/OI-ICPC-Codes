#include <cstdio>
#define MAXN 1000010
#define MAXA 5005
#define MAXK 505
using namespace std;

int n, k, p, l, r, a[MAXN], diff[MAXN];
inline int lowbit(int x)
{
	return x & -x;
}

inline void modify(int x, int v)
{
	for (; x <= n; x += lowbit(x)) diff[x] += v;
	return ;
}

inline int query(int x)
{
	int ans = 0;
	for (; x; x -= lowbit(x)) ans += diff[x];
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

namespace Subtask1
{
	int c[MAXA + MAXK][MAXK], now, ans, mxa;
	inline int mymax(int a, int b)
	{
		return a > b ? a : b;
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
	inline void Solve()
	{
		for (int i = 1; i <= n; i++) mxa = mymax(mxa, a[i]);
		for (int i = 1; i <= n; i++)
			for (int j = k; ~j; j--)
			{
				now = query(a[i] + j, j + 1) + 1;
				ans = mymax(now, ans);
				modify(a[i] + j, j + 1, now);
			}
		printf("%d\n", ans);
		return ;
	}
}

namespace Subtask2
{
	int dp[MAXN], ans;
	inline int binary(int x)
	{
		int l = 0, r = ans, mid;
		while (l < r)
		{
			mid = l + r >> 1;
			if (dp[mid] <= x) l = mid + 1;
			else r = mid;
		}
		return l;
	}
	inline void Solve()
	{
		for (int i = 1; i <= n; i++)
		{
			if (a[i] >= dp[ans]) dp[++ans] = a[i];
			else dp[binary(a[i])] = a[i];
		}
		printf("%d\n", ans);
		return ;
	}
}

int main()
{
	read(n);
	read(k);
	read(p);
	k -= p;
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= p; i++)
	{
		read(l);
		read(r);
		modify(l, 1);
		modify(r + 1, -1);
	}
	for (int i = 1; i <= n; i++) a[i] += query(i);
	if (k) Subtask1::Solve();
	else Subtask2::Solve();
	return 0;
}