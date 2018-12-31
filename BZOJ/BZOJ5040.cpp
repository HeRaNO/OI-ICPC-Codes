#include <cstdio>
#include <algorithm>
#define MAXN 550010
#define MAXQ 400010
using namespace std;

char ib[20000007], *ip = ib;
void read(int &x)
{
	x = 0;
	while (*ip < '0' || *ip > '9') ++ip;
	while (*ip >= '0' && *ip <= '9') x = x * 10 + *ip++ -48;
	return ;
}

struct History
{
	int l, r, id, len;
	long long ans;
	bool operator < (const History &a)const
	{
		return l == a.l ? r < a.r : l < a.l;
	}
};

History ask[MAXQ];
int head[MAXQ], ecnt;
int n, m, T, R, a[MAXN], tim[MAXN];
int pt = 1, father[MAXQ], son[MAXQ], seq[MAXQ];
long long ans, ori[MAXN], cnt[MAXN], qry[MAXQ];
pair <int, int *> b[MAXN];

inline void dfs()
{
	for (int x = pt++, w; pt <= T && ask[pt].r <= ask[x].r;)
	{
		w = pt;
		father[pt] = x;
		dfs();
		if (ask[w].len > ask[son[x]].len) son[x] = w;
	}
	return ;
}

inline void modify(int x)
{
	if (tim[x] != R)
	{
		tim[x] = R;
		cnt[x] = 0;
	}
	cnt[x] += ori[x];
	if (ans < cnt[x]) ans = cnt[x];
	return ;
}

inline void Calculate(int x)
{
	for (int u = x; u; u = son[u]) seq[++pt] = u;
	int l = ask[seq[pt]].l, r = l - 1;
	for (ans = 0LL, ++R; pt; qry[ask[x].id] = ans)
	{
		x = seq[pt--];
		while (l > ask[x].l) modify(a[--l]);
		while (r < ask[x].r) modify(a[++r]);
	}
	return ;
}

int main()
{
	fread(ib, 1, sizeof ib, stdin);
	read(n);
	read(T);
	for (int i = 1; i <= n; i++) read(a[i]), b[i] = make_pair(a[i], &a[i]);
	for (int i = 1; i <= T; i++)
	{
		ask[i].id = i;
		read(ask[i].l);
		read(ask[i].r);
		ask[i].len = ask[i].r - ask[i].l + 1;
	}
	sort(ask + 1, ask + T + 1);
	sort(b + 1, b + n + 1);
	while (pt <= T) dfs();
	for (int i = 1; i <= n; i++)
	{
		if (b[i].first != b[i - 1].first) ori[++m] = b[i].first;
		*b[i].second = m;
	}
	for (int i = 1; i <= T; i++) if (son[father[i]] != i) Calculate(i);
	for (int i = 1; i <= T; i++) printf("%lld\n", qry[i]);
	return 0;
}