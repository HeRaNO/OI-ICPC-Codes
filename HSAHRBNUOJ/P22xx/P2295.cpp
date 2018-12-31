#include <cstdio>
#include <cstring>
#define MAXN 505
using namespace std;

int n, m, l, r, mid, ans, a[MAXN], arr[MAXN][2];
int pt, ptt, x;

inline void max(int &a, int b)
{
	if (a < b) a = b;
	return ;
}

inline bool check(int x)
{
	int t = 0, cnt = 1;
	for (int i = 1; i <= n; i++)
	{
		if (t + a[i] <= x) t += a[i];
		else
		{
			t = a[i];
			cnt++;
			if (cnt > m) return false;
		}
	}
	return cnt <= m;
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
	read(m);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		max(l, a[i]);
		r += a[i];
	}
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (check(mid))
		{
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	pt = n;
	for (int i = n; i; i--)
	{
		x += a[i];
		if (x > ans)
		{
			arr[++ptt][0] = i + 1;
			arr[ptt][1] = pt;
			pt = i;
			x = a[i];
		}
	}
	if (pt) arr[++ptt][0] = 1;
	arr[ptt][1] = pt;
	for (int i = ptt; i; i--) printf("%d %d\n", arr[i][0], arr[i][1]);
	return 0;
}