#include <cstdio>
#include <climits>
#include <algorithm>
#define MAXN 100005
#define MAXM 200005
using namespace std;

struct edge
{
	int from;
	int to;
	int val;
	bool type; //Ò»¼¶:1
};

struct link
{
	int to;
	int val;
	int nxt;
};

edge edges[MAXM];
link tree[2 * MAXN];
int n, m, k;
int u, v, w1, w2;
int father[MAXN];

bool cmp(edge a, edge b)
{
	return a.val < b.val;
}

int getfather(int x)
{
	return father[x] == x ? x : father[x] = getfather(father[x]);
}

bool kruskal_judge(int limit)
{
	for (int i = 1; i <= n; i++) father[i] = i;
	int cnt = 0;
	for (int i = 1; i <= m && edges[i].val <= limit; i++)
		if (edges[i].type)
		{
			int x = getfather(edges[i].from);
			int y = getfather(edges[i].to);
			if (x != y) father[y] = x, cnt++;
		}
	if (cnt < k) return false;
	for (int i = 1; i <= m && edges[i].val <= limit; i++)
	{
		int x = getfather(edges[i].from);
		int y = getfather(edges[i].to);
		if (x != y) father[y] = x, cnt++;
	}
	return cnt == n - 1;
}

int binary()
{
	int left = 1, right = 30000, middle;
	while (left < right)
	{
		middle = (left + right) >> 1;
		if (kruskal_judge(middle)) right = middle;
		else left = middle + 1;
	}
	return right;
}

int main()
{
	//freopen("route.in","r",stdin);freopen("route.out","w",stdout);
	scanf("%d %d %d", &n, &k, &m);
	m--;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d %d", &u, &v, &w1, &w2);
		edges[(i << 1) - 1].from = edges[i << 1].from = u;
		edges[(i << 1) - 1].to = edges[i << 1].to = v;
		edges[(i << 1) - 1].type = true;
		edges[(i << 1) - 1].val = w1;
		edges[i << 1].type = false;
		edges[i << 1].val = w2;
	}
	m <<= 1;
	sort(edges + 1, edges + m + 1, cmp);
	printf("%d", binary());
	return 0;
}