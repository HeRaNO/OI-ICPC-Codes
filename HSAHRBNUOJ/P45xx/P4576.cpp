#include <cstdio>
#include <algorithm>
#define MAXN 10010
#define MAXM 100010
using namespace std;

struct link
{
	int from, to, val;
	bool operator < (const link &a)const
	{
		return val < a.val;
	}
};

link e[MAXM];
int n, m, cnt, ans = ~(1 << 31), w, fx, fy, f[MAXN], a[MAXN];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline int getf(int x)
{
	return x == f[x] ? x : f[x] = getf(f[x]);
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
	read(m);
	for (int i = 1; i <= n; i++) read(a[i]), ans = mymin(ans, a[i]), f[i] = i;
	for (int i = 1; i <= m; i++)
	{
		read(e[i].from);
		read(e[i].to);
		read(w);
		e[i].val = a[e[i].from] + a[e[i].to] + (w << 1);
	}
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; i++)
	{
		fx = getf(e[i].from);
		fy = getf(e[i].to);
		if (fx != fy)
		{
			ans += e[i].val;
			cnt++;
			f[fy] = fx;
		}
		if (cnt == n - 1) break;
	}
	printf("%d\n", ans);
	return 0;
}