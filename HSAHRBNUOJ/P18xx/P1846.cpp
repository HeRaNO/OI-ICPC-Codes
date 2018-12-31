#include <cstdio>
#include <algorithm>
#define MAXN 1010
#define MAXM 100010
using namespace std;

struct link
{
	int from;
	int to;
	int val;
};

link e[MAXM];
int n, m, u, v, w, cnt;
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
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		e[i] = (link)
		{
			u, v, w
		};
	}
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int fx = getfather(e[i].from);
		int fy = getfather(e[i].to);
		if (fx != fy)
		{
			father[fy] = fx;
			cnt++;
			if (cnt == n - 1)
			{
				printf("%d\n", e[i].val);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}
