#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 505
#define MAXM 20000
#define MAXL 30
using namespace std;

struct link
{
	int to, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt;
int n, m, k, S, T, ans;
int dpt[MAXN], father[MAXL];
int H[MAXL], r[MAXL], s[MAXL][MAXL];
queue <int> q;

inline int getfather(int x)
{
	return father[x] == x ? x : father[x] = getfather(father[x]);
}

inline void Merge(int x, int y)
{
	father[getfather(x)] = getfather(y);
	return ;
}

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline int GetHash(int x, int d)
{
	return d * n + x;
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

inline int check(int lim)
{
	int ans = 0;
	memset(head, 0, sizeof head);
	cnt = 1;
	S = 0;
	T = 500;
	for (int Day = 0; Day <= lim; Day++)
	{
		add(S, GetHash(2, Day), ~(1 << 31));
		add(GetHash(1, Day), T, ~(1 << 31));
		if (Day)
		{
			for (int i = 1; i <= m; i++)
				add(GetHash(s[i][(Day - 1) % r[i]], Day - 1), GetHash(s[i][Day % r[i]], Day), H[i]);
			for (int i = 1; i <= n; i++)
				add(GetHash(i, Day - 1), GetHash(i, Day), ~(1 << 31));
		}
	}
	while (BFS()) ans += Dinic(S, ~(1 << 31));
	return ans;
}

inline int Binary()
{
	int l = 0, r = 30, mid, ans;
	while (l <= r)
	{
		mid = l + r >> 1;
		if (check(mid) >= k) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	//freopen("home.in","r",stdin);freopen("home.out","w",stdout);
	read(n);
	read(m);
	read(k);
	n += 2;
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i <= m; i++)
	{
		read(H[i]);
		read(r[i]);
		for (int j = 0; j < r[i]; j++)
		{
			read(s[i][j]);
			s[i][j] += 2;
			if (j) Merge(s[i][j], s[i][j - 1]);
		}
	}
	if (getfather(1) != getfather(2))
	{
		puts("0");
		return 0;
	}
	printf("%d\n", Binary());
	return 0;
}