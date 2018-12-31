#include <cstdio>
#include <cstring>
#define MAXM 2000010
#define MAXN 1000010
using namespace std;

struct link
{
	int to;
	long long val;
	int nxt;
};

link e[MAXM];
int n, m, cnt, f, t;
int edge_num[MAXN];
int head1, tail1, head2, tail2;
long long d, ans;
long long dp1[MAXN], dp2[MAXN];
long long a[MAXN], q1[MAXN], q2[MAXN];

void add(int u, int v, long long w)
{
	e[cnt] = (link)
	{
		v, w, edge_num[u]
	};
	edge_num[u] = cnt++;
	e[cnt] = (link)
	{
		u, w, edge_num[v]
	};
	edge_num[v] = cnt++;
}

long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}

void dfs1(int node, int father) //down
{
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
	{
		if (e[i].to != father)
		{
			dfs1(e[i].to, node);
			dp1[node] = mymax(dp1[node], dp1[e[i].to] + e[i].val);
		}
	}
}

void dfs2(int node, int father) //up
{
	long long mx = 0, cmx = 0;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
	{
		if (e[i].to != father)
		{
			if (dp1[e[i].to] + e[i].val > mx)
			{
				cmx = mx;
				mx = dp1[e[i].to] + e[i].val;
			}
			else cmx = mymax(cmx, dp1[e[i].to] + e[i].val);
			dp2[e[i].to] = dp2[node] + e[i].val;
		}
	}
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
	{
		if (e[i].to != father)
		{
			if (dp1[e[i].to] + e[i].val == mx) dp2[e[i].to] = mymax(dp2[e[i].to], e[i].val + cmx);
			else dp2[e[i].to] = mymax(dp2[e[i].to], e[i].val + mx);
			dfs2(e[i].to, node);
		}
	}
}

inline void Monotonous_Queue()
{
	head1 = head2 = 1;
	tail1 = tail2 = 0;
	t = 1;
	for (int i = 1; i <= n; i++)
	{
		while (head1 <= tail1 && a[i] <= a[q1[tail1]]) tail1--;
		while (head2 <= tail2 && a[i] >= a[q2[tail2]]) tail2--;
		q1[++tail1] = i;
		q2[++tail2] = i;
		while (a[q2[head2]] - a[q1[head1]] > m)
		{
			if (q2[head2] <= q1[head1]) t = q2[head2] + 1, head2++;
			else t = q1[head1] + 1, head1++;
		}
		ans = mymax(ans, i - t + 1);
	}
	return ;
}

int main()
{
	freopen("drawing.in", "r", stdin);
	freopen("drawing.out", "w", stdout);
	memset(edge_num, -1, sizeof(edge_num));
	scanf("%d %d", &n, &m);
	for (int i = 2; i <= n; i++)
	{
		scanf("%d %lld", &f, &d);
		add(i, f, d);
	}
	dfs1(1, -1);
	dfs2(1, -1);
	for (int i = 1; i <= n; i++) a[i] = mymax(dp1[i], dp2[i]);
	Monotonous_Queue();
	printf("%lld\n", ans);
	return 0;
}
