#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 210
#define MAXM 20000
using namespace std;

struct link
{
	int to, val, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt = 1;
int n, m, S, T, x, y, ans, flow;
int dis[MAXN], from[MAXN], f[MAXN];
bool vis[MAXN];
string a, b, name[MAXN >> 1];
map <string, int> mp;
map <string, int> :: iterator it1, it2;
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
	return ;
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
			if (dis[e[i].to] < dis[u] + e[i].val && e[i].flow)
			{
				dis[e[i].to] = dis[u] + e[i].val;
				from[e[i].to] = i;
				f[e[i].to] = mymin(f[u], e[i].flow);
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
	}
	if (!f[T]) return false;
	ans += dis[T] * f[T];
	flow += f[T];
	for (int i = from[T]; i; i = from[e[i ^ 1].to])
		e[i].flow -= f[T], e[i ^ 1].flow += f[T];
	return true;
}

inline void GetMethod(int x)
{
	vis[x] = true;
	for (int i = head[x]; i; i = e[i].nxt)
		if (!vis[e[i].to] && ((!e[i].flow && e[i].val >= 0) || (e[i].flow && e[i].val <= 0)))
		{
			GetMethod(e[i].to);
			if (e[i].to <= n) cout << name[e[i].to] << endl;
		}
	return ;
}

int main()
{
	//freopen("airl.in","r",stdin);freopen("airl.out","w",stdout);
	cin >> n >> m;
	S = 1;
	T = n << 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> name[i];
		mp.insert(make_pair(name[i], i));
		if (i == 1 || i == n) add(i, i + n, 0, 2);
		else add(i, i + n, 0, 1);
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		it1 = mp.find(a);
		it2 = mp.find(b);
		x = it1->second;
		y = it2->second;
		if (x > y) swap(x, y);
		if (x == 1 && y == n) add(x + n, y, 1, 2);
		else add(x + n, y, 1, 1);
	}
	while (Edmonds_Karp());
	if (flow == 2)
	{
		memset(vis, false, sizeof vis);
		printf("%d\n", ans);
		cout << name[1] << endl;
		GetMethod(1);
		cout << name[1] << endl;
	}
	else puts("No Solution!");
	return 0;
}