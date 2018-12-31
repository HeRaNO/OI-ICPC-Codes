#include <cstdio>
#include <algorithm>
#define MAXN 110
#define MAXM 10010
using namespace std;

struct link
{
	int from, to, val;
};

link e[MAXM];
int father[MAXN];
int n, m, ans = ~(1 << 31);

bool cmp(link a, link b)
{
	return a.val < b.val;
}
inline int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}
inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

int KrusKal(int x)
{
	int cnt = 0, maxx = 0;
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = x; i <= m; i++)
	{
		int fx = getfather(e[i].from), fy = getfather(e[i].to);
		if (fx != fy)
		{
			father[fy] = fx;
			cnt++;
			maxx = mymax(maxx, e[i].val);
		}
		if (cnt == n - 1) break;
	}
	if (cnt != n - 1) return ~(1 << 31);
	return maxx - e[x].val;
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
	//freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	read(n);
	read(m);
	if (m < n - 1)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= m; i++)
	{
		read(e[i].from);
		read(e[i].to);
		read(e[i].val);
	}
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m - n + 2; i++) ans = mymin(ans, KrusKal(i));
	printf("%d\n", ans == ~(1 << 31) ? -1 : ans);
	return 0;
}
