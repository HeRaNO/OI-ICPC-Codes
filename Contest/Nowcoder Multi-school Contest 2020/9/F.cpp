#include <cstdio>
#include <algorithm>
#define MAXN  1000005
#define MAXNK 2000005
using namespace std;

struct _808
{
	int p, x;
	_808(){}
	_808(int _p, int _x): p(_p), x(_x){}
	bool operator < (const _808 &a) const {
		return p == a.p ? x < a.x : p < a.p;
	}
};

_808 a[MAXNK];
int n, m, k, x, p, d, vis[MAXN], N;
int ans = ~(1<<31), cnt = 1, pt = 1;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &p);
		for (int j = 1; j <= p; j++)
			scanf("%d", &x), a[++N] = _808(x, i);
	}
	sort(a + 1, a + N + 1);
	vis[a[1].x] = 1;
	for (int i = 1; i <= N; i++)
	{
		while (pt < N && cnt < m)
		{
			++pt;
			if (!vis[a[pt].x]) ++cnt;
			++vis[a[pt].x];
		}
		if (cnt == m) ans = min(ans, a[pt].p - a[i].p);
		if (vis[a[i].x] == 1) --cnt;
		--vis[a[i].x];
	}
	printf("%d\n", ans);
	return 0;
}
