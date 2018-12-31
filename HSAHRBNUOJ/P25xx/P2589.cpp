#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 2000010
#define MAXM 2000010
using namespace std;

struct link
{
	int from;
	int to;
	long long val;
};

link e[MAXM];
int father[MAXN], son[MAXN];
int edge_num[MAXN];
int n, m, k, cnt, num;
long long ans;
int u, v;
long long w;

inline void pre_work()
{
	memset(edge_num, -1, sizeof(edge_num));
	for (int i = 0; i <= n; i++) father[i] = i, son[i] = 1;
	return ;
}

int getfather(int x)
{
	return father[x] == x ? x : getfather(father[x]);
}

void quickSort(int left, int right)
{
	int l = left, r = right;
	long long mid = e[(left + right) / 2].val;
	while (l <= r)
	{
		while (e[l].val < mid) l++;
		while (e[r].val > mid) r--;
		if (l <= r)
		{
			swap(e[l], e[r]);
			l++, r--;
		}
	}
	if (left < r) quickSort(left, r);
	if (l < right) quickSort(l, right);
}

int main()
{
	//freopen("b.in","r",stdin);freopen("b.out","w",stdout);
	scanf("%d %d %d", &n, &m, &k);
	pre_work();
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %lld", &u, &v, &w);
		e[i].from = u;
		e[i].to = v;
		e[i].val = w;
	}
	quickSort(1, m);
	for (int i = 1; i <= m; i++)
	{
		int x = getfather(e[i].from);
		int y = getfather(e[i].to);
		if (x != y)
		{
			ans += e[i].val;
			son[y] += son[x];
			father[x] = y;
			num++;
			if (num == n - 1) break;
		}
	}
	int t = getfather(k);
	if (son[t] < n) printf("%d\n", n - son[t]);
	else printf("%lld\n", ans);
	return 0;
}
