#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 10000
#define MAXM 50000
using namespace std;

struct link
{
	int to;
	long long val;
	int nxt;
};

struct node
{
	long long d;
	int u;
	bool operator < (const node &a)const
	{
		return d > a.d;
	}
};

link e[MAXM << 1];
int head[MAXN], cnt;
int n, m, u, v, w, S, T, L, R, a[MAXN];
long long dis[MAXN];
bool vis[MAXN];
priority_queue <node> q;

inline void add(int u, int v, long long w)
{
	e[cnt] = (link)
	{
		v, w, head[u]
	};
	head[u] = cnt++;
	e[cnt] = (link)
	{
		u, w, head[v]
	};
	head[v] = cnt++;
}

inline bool Dijkstra(int x)
{
	if (a[S] > x || a[T] > x) return false;
	memset(vis, false, sizeof vis);
	for (int i = 1; i <= n; i++) dis[i] = 1e15;
	q.push((node)
	{
		0LL, S
	});
	dis[S] = 0LL;
	while (!q.empty())
	{
		node t = q.top();
		q.pop();
		if (vis[t.u]) continue;
		vis[t.u] = true;
		for (int i = head[t.u]; ~i; i = e[i].nxt)
			if (a[e[i].to] <= x && dis[e[i].to] > dis[t.u] + e[i].val)
			{
				dis[e[i].to] = dis[t.u] + e[i].val;
				q.push((node)
				{
					dis[e[i].to], e[i].to
				});
			}
	}
	return dis[T] <= (long long)L;
}

inline int Binary()
{
	int l = 0, r = 1e9, mid, ans = -1;
	while (l <= r)
	{
		mid = l + r >> 1;
		if (Dijkstra(mid))
		{
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
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
	//freopen("cost.in","r",stdin);freopen("cost.out","w",stdout);
	memset(head, -1, sizeof head);
	read(n);
	read(m);
	read(S);
	read(T);
	read(L);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		read(w);
		add(u, v, (long long)w);
	}
	printf("%d\n", Binary());
	return 0;
}