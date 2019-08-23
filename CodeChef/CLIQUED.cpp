#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 100005
#define MAXM 500005
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
int n, k, m, delta, S, T, x, y, z;
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

inline void Dijkstra(int S)
{
	memset(dis, 0x3f, sizeof dis);
	memset(vis, false, sizeof vis);
	q.push((node){0, S});
	dis[S] = 0;
	while (!q.empty())
	{
		node x = q.top();
		q.pop();
		if (vis[x.u]) continue;
		vis[x.u] = true;
		for (int i = head[x.u]; ~i; i = e[i].nxt)
			if (dis[e[i].to] > dis[x.u] + e[i].val)
			{
				dis[e[i].to] = dis[x.u] + e[i].val;
				q.push((node){dis[e[i].to], e[i].to});
			}
	}
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(T);
	while (T--)
	{
		memset(head, -1, sizeof head);
		cnt = 0;
		read(n);
		read(k);
		read(delta);
		read(m);
		read(S);
		if (S <= k)
		{
			for (int i = 1; i <= k; i++) if (S != i) add(S, i, delta);
			for (int i = 1; i <= m; i++)
			{
				read(x);
				read(y);
				read(z);
				add(x, y, z);
			}
		}
		else
		{
			for (int i = 1; i <= m; i++)
			{
				read(x);
				read(y);
				read(z);
				add(x, y, z);
			}
		}
		Dijkstra(S);
		bool f = true;
		if (S <= k)
		{
			for (int i = 1; i <= n; i++)
			{
				if (f)
				{
					printf("%lld", dis[i]);
					f = false;
				}
				else printf(" %lld", dis[i]);
			}
		}
		else
		{
			long long mn = 1e18;
			int pt;
			for (int i = 1; i <= k; i++)
				if (dis[i] < mn) mn = dis[i], pt = i;
			for (int i = 1; i <= k; i++)
				if (pt != i) add(pt, i, delta);
			Dijkstra(S);
			for (int i = 1; i <= n; i++)
			{
				if (f)
				{
					printf("%lld", dis[i]);
					f = false;
				}
				else printf(" %lld", dis[i]);
			}
		}
		puts("");
	}
	return 0;
}