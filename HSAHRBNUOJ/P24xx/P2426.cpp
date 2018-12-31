#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 310
#define MAXM 20000
#define MAXT 32768
using namespace std;

struct link
{
	int to, flow, nxt;
};

struct Segment
{
	int l, r, len;
};

link e[MAXM << 1];
Segment a[MAXT];
int CAS, n, m, sum, S, T, ans, x, segcnt;
int head[MAXN], cnt, mxt;
int dpt[MAXN], s[MAXN], t[MAXN];
bool stp[MAXT];
queue <int> q;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void Prepare()
{
	cnt = segcnt = 1;
	ans = sum = mxt = 0;
	memset(head, 0, sizeof head);
	memset(stp, false, sizeof stp);
	return ;
}

inline void add(int u, int v, int f)
{
	e[++cnt] = (link)
	{
		v, f, head[u]
	};
	head[u] = cnt;
	e[++cnt] = (link)
	{
		u, 0, head[v]
	};
	head[v] = cnt;
}

inline bool BFS()
{
	memset(dpt, -1, sizeof dpt);
	dpt[S] = 1;
	q.push(S);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nxt)
			if (e[i].flow && !~dpt[e[i].to])
			{
				dpt[e[i].to] = dpt[u] + 1;
				q.push(e[i].to);
			}
	}
	return dpt[T] != -1;
}

inline int Dinic(int x, int flow)
{
	int left = flow;
	if (x == T) return flow;
	for (int i = head[x]; i && left; i = e[i].nxt)
		if (e[i].flow && dpt[e[i].to] == dpt[x] + 1)
		{
			int t = Dinic(e[i].to, mymin(e[i].flow, left));
			e[i].flow -= t;
			e[i ^ 1].flow += t;
			left -= t;
		}
	if (left) dpt[x] = -1;
	return flow - left;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(CAS);
	while (CAS--)
	{
		Prepare();
		read(n);
		read(m);
		for (int i = 1; i <= n; i++)
		{
			read(x);
			read(s[i]);
			read(t[i]);
			stp[s[i]] = stp[t[i]] = true;
			sum += x;
			mxt = mymax(mxt, t[i]);
			add(S, i, x);
		}
		for (int i = 1; i <= mxt; i++)
			if (stp[i])
			{
				a[segcnt].r = i - 1;
				a[segcnt].len = i - a[segcnt].l;
				a[++segcnt].l = i;
			}
		segcnt--;
		T = segcnt + n + 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= segcnt; j++)
				if (s[i] <= a[j].l && a[j].r <= t[i] + 1) add(i, j + n, a[j].len);
		for (int i = 1; i <= segcnt; i++) add(i + n, T, a[i].len * m);
		while (BFS()) ans += Dinic(S, ~(1 << 31));
		if (ans == sum) puts("Yes");
		else puts("No");
	}
	return 0;
}