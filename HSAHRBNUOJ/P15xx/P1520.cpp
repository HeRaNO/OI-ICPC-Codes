#include <cstdio>
#include <algorithm>
#define MAXN 1010
#define MAXM 20010
using namespace std;

struct link
{
	int from;
	int to;
	int val;
};

link e[MAXM];
int n, m, mst_cnt, ans;
int father[MAXN];

int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}
bool cmp(link a, link b)
{
	return a.val > b.val;
}

int main()
{
	scanf("%d %d", &n, &m);
	if (m < n - 1)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= m; i++) scanf("%d %d %d", &e[i].from, &e[i].to, &e[i].val);
	for (int i = 1; i <= n; i++) father[i] = i;
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; i++)
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
	if (mst_cnt != n - 1) puts("-1");
	else printf("%d\n", ans);
	return 0;
}
