#pragma GCC optimize("O2")
#include <map>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 65
#define MAXM 1000
#define fi first
#define se second
using namespace std;

struct link
{
	int to, val, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt = 1, S, T, ans;
int dis[MAXN], f[MAXN], from[MAXN];
bool vis[MAXN];
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v, int c, int f)
{
	e[++cnt] = (link)
	{
		v, c, f, head[u]
	};
	head[u] = cnt;
	e[++cnt] = (link)
	{
		u, -c, 0, head[v]
	};
	head[v] = cnt;
}

inline bool Edmonds_Karp()
{
	for (int i = S; i <= T; i++) dis[i] = 1 << 31;
	memset(vis, false, sizeof vis);
	q.push(S);
	dis[S] = 0;
	vis[S] = true;
	f[S] = ~(1 << 31);
	f[T] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; i; i = e[i].nxt)
			if (e[i].flow && dis[e[i].to] < dis[u] + e[i].val)
			{
				dis[e[i].to] = dis[u] + e[i].val;
				f[e[i].to] = mymin(e[i].flow, f[u]);
				from[e[i].to] = i;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
	}
	if (dis[T] == 1 << 31) return false;
	ans += dis[T];
	for (int i = from[T]; i; i = from[e[i ^ 1].to])
		e[i].flow -= f[T], e[i ^ 1].flow += f[T];
	return true;
}

int K, n, a[MAXN >> 1][MAXN >> 1], B, G, A;
bool flag;
pair <int, int> p[MAXN];
map <string, int> mp;
map <string, int> :: iterator it;
string x, ed("End");

inline int Getdis(pair<int, int> a, pair<int, int> b)
{
	return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
}

inline bool in(int l, int x, int r)
{
	if (l > r) swap(l, r);
	return x <= r && x >= l;
}

inline void Trim(string &a)
{
	for (string::iterator it = a.begin(); it != a.end(); it++)
		if (*it >= 'a') *it -= 32;
	return ;
}

int main()
{
	cin >> K >> n;
	T = (n << 1) + 1;
	K *= K;
	for (int i = 1; i <= (n << 1); i++)
	{
		cin >> p[i].fi >> p[i].se >> x;
		Trim(x);
		mp.insert(make_pair(x, i));
	}
	while (cin >> x)
	{
		if (x == ed) break;
		Trim(x);
		it = mp.find(x);
		B = it->se;
		cin >> x >> A;
		Trim(x);
		it = mp.find(x);
		G = it->se;
		if (B > G) swap(B, G);
		a[B][G] = A - 1;
	}
	for (int i = 1; i <= n; i++)
	{
		add(S, i, 0, 1);
		add(i + n, T, 0, 1);
		for (int j = n + 1; j <= (n << 1); j++)
		{
			if (Getdis(p[i], p[j]) > K) continue;
			flag = true;
			for (int k = 1; k <= (n << 1) && flag; k++)
			{
				if (k == i || k == j) continue;
				if (!in(p[i].fi, p[k].fi, p[j].fi)) continue;
				if (!in(p[i].se, p[k].se, p[j].se)) continue;
				if ((p[i].fi - p[j].fi) * (p[k].se - p[j].se) == (p[i].se - p[j].se) * (p[k].fi - p[j].fi))
					flag = false;
			}
			if (flag) add(i, j, a[i][j] + 1, 1);
		}
	}
	while (Edmonds_Karp());
	printf("%d\n", ans);
	return 0;
}