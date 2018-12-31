#include <cstdio>
#include <algorithm>
#define MAXN 110
using namespace std;

struct link
{
	int from;
	int to;
	int val;
};

link e[MAXN * MAXN];
int father[MAXN];
int n, a[MAXN][MAXN];
int cnt, mst_cnt, ans;

int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}
bool cmp(link a, link b)
{
	return a.val < b.val;
}

int main()
{
	for (int i = 0; i < MAXN; i++) father[i] = i;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			e[++cnt] = (link)
		{
			i, j, a[i][j]
		};
	sort(e + 1, e + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++)
	{
		if (mst_cnt == n - 1) break;
		int x = getfather(e[i].from);
		int y = getfather(e[i].to);
		if (x != y)
		{
			father[y] = x;
			mst_cnt++;
			ans += e[i].val;
		}
	}
	printf("%d\n", ans);
	return 0;
}
