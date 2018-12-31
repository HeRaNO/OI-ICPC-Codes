#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 100010
#define MOD 1000000007LL

struct link
{
	int to;
	int nxt;
};

link e[2 * MAXN];
int n, T, opt, cnt, u, v;
int edge_num[MAXN];
int dp1[MAXN][2], dp2[MAXN][2];
int son[MAXN], siz;
long long l, suml, sumr[MAXN], r[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = cnt++;
	e[cnt] = (link)
	{
		u, edge_num[v]
	};
	edge_num[v] = cnt++;
}

void TreeDP(int node, int father)
{
	long long mx, tmp;
	dp2[node][0] = 1LL;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
	{
		if (e[i].to == father) continue;
		TreeDP(e[i].to, node);
		mx = mymax(dp1[e[i].to][0], dp1[e[i].to][1]);
		tmp = 0LL;
		if (dp1[e[i].to][0] == mx) tmp += dp2[e[i].to][0];
		if (dp1[e[i].to][1] == mx) tmp += dp2[e[i].to][1];
		dp2[node][0] = (dp2[node][0] * tmp) % MOD;
		dp1[node][0] += mx;
	}
	siz = 0;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != father) son[++siz] = e[i].to;
	l = 0LL;
	suml = 1LL;
	sumr[siz + 1] = 1LL;
	r[siz + 1] = 0LL;
	for (int i = siz; i; i--)
	{
		mx = mymax(dp1[son[i]][0], dp1[son[i]][1]);
		tmp = 0LL;
		if (mx == dp1[son[i]][0]) tmp += dp2[son[i]][0];
		if (mx == dp1[son[i]][1]) tmp += dp2[son[i]][1];
		r[i] = r[i + 1] + mx;
		sumr[i] = (sumr[i + 1] * tmp) % MOD;
	}
	dp1[node][1] = INT_MIN;
	for (int i = 1; i <= siz; i++)
	{
		tmp = l + dp1[son[i]][0] + r[i + 1] + 1;
		if (tmp > dp1[node][1])
		{
			dp1[node][1] = tmp;
			dp2[node][1] = (dp2[son[i]][0] * ((suml * sumr[i + 1]) % MOD)) % MOD;
		}
		else if (tmp == dp1[node][1])
			dp2[node][1] = (dp2[node][1] + (dp2[son[i]][0] * ((suml * sumr[i + 1]) % MOD)) % MOD) % MOD;
		mx = mymax(dp1[son[i]][0], dp1[son[i]][1]);
		tmp = 0LL;
		if (mx == dp1[son[i]][0]) tmp += dp2[son[i]][0];
		if (mx == dp1[son[i]][1]) tmp += dp2[son[i]][1];
		suml = (suml * tmp) % MOD;
		l += mx;
	}
	return ;
}

int main()
{
	scanf("%d %d", &T, &opt);
	opt--;
	while (T--)
	{
		memset(dp1, 0, sizeof dp1);
		memset(dp2, 0, sizeof dp2);
		cnt = 0;
		memset(edge_num, -1, sizeof edge_num);
		scanf("%d", &n);
		for (int i = 1; i < n; i++)
		{
			scanf("%d %d", &u, &v);
			add(u, v);
		}
		TreeDP(1, 1);
		long long ans1 = mymax(dp1[1][0], dp1[1][1]);
		if (!opt) printf("%lld\n", ans1);
		else
		{
			long long ans2 = 0;
			if (ans1 == dp1[1][0]) ans2 += dp2[1][0];
			if (ans1 == dp1[1][1]) ans2 += dp2[1][1];
			ans2 = ans2 % MOD;
			printf("%lld %lld\n", ans1, ans2);
		}
	}
	return 0;
}
