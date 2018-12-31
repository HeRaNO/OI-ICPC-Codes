#include <cstdio>
#include <algorithm>
#define MAXN 1000010
#define MAXT 700010
using namespace std;

struct homework
{
	int t;
	int v;
};

homework a[MAXN];
int father[MAXT];
int n, ans;

bool cmp(homework a, homework b)
{
	if (a.v == b.v) return a.t > b.t;
	return a.v > b.v;
}

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		a[i].t = read();
		a[i].v = read();
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i < MAXT; i++) father[i] = i;
	for (int i = 1; i <= n; i++)
	{
		int fa = getfather(a[i].t);
		if (fa)
		{
			ans += a[i].v;
			father[fa] = fa - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
