#include <cstdio>
#include <algorithm>
#define MAXN 110
#define MAXM 5010
using namespace std;

struct link
{
	int from;
	int to;
	int val;
};

link e[MAXM];
int n, m, mst_cnt, ans = ~(1 << 31);
int father[MAXN];

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
	scanf("%d %d", &n, &m);
	if (m < n - 1)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= m; i++) scanf("%d %d %d", &e[i].from, &e[i].to, &e[i].val);
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m - n + 1; i++)
	{
		for (int j = 1; j <= n; j++) father[j] = j;
		father[e[i].to] = e[i].from;
		mst_cnt = 1;
		for (int j = i + 1; j <= m; j++)
		{
			if (e[j].val - e[i].val >= ans) break;
			int x = getfather(e[j].from);
			int y = getfather(e[j].to);
			if (x != y)
			{
				father[y] = x;
				mst_cnt++;
				if (mst_cnt == n - 1) ans = e[j].val - e[i].val;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
