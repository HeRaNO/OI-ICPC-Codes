#include <cstdio>
#include <algorithm>
#define MAXN 1010
#define MAXM 10010
using namespace std;

struct link
{
	int from;
	int to;
	int val;
};

link e[MAXM];
int father[MAXN];
int n, m, k;
int cnt, ans;

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
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) scanf("%d %d %d", &e[i].from, &e[i].to, &e[i].val);
	for (int i = 1; i <= n; i++) father[i] = i;
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; i++)
	{
		int fx = getfather(e[i].from);
		int fy = getfather(e[i].to);
		if (fx != fy)
		{
			father[fx] = fy;
			cnt++;
			ans += e[i].val;
			if (cnt == n - k)
			{
				printf("%d\n", ans);
				return 0;
			}
		}
	}
	printf("No Answer\n");
	return 0;
}
