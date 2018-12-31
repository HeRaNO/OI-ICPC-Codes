#include <cstdio>
#include <algorithm>
#define MAXN 2010
#define MAXM 10010
using namespace std;

struct link
{
	int fr, to, val;
};

link e[MAXM];
int n, m, ans, f[MAXN];

bool cmp(link a, link b)
{
	return a.val < b.val;
}

inline int getfather(int x)
{
	return x == f[x] ? x : f[x] = getfather(f[x]);
}

inline void Kruskal()
{
	int cnt = 0, fx, fy;
	for (int i = 1; i <= m; i++)
	{
		fx = getfather(e[i].fr);
		fy = getfather(e[i].to);
		if (fx != fy)
		{
			ans = e[i].val;
			f[fy] = fx;
			cnt++;
		}
		if (cnt == n - 1) break;
	}
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
	read(m);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++) read(e[i].fr), read(e[i].to), read(e[i].val);
	sort(e + 1, e + m + 1, cmp);
	Kruskal();
	printf("%d\n", ans);
	return 0;
}