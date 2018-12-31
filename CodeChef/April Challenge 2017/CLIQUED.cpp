#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 100010
#define MAXM 500010
using namespace std;

struct link
{
	int to;
	long long val;
	int nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt;
int n, k, m, delta, S, T, x, y, z;
long long dis[MAXN];
bool vis[MAXN];
queue <int> q;

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

inline void SPFA(int S)
{
	memset(vis, false, sizeof vis);
	for (int i = 1; i <= n; i++) dis[i] = 1e16;
	q.push(S);
	vis[S] = true;
	dis[S] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; ~i; i = e[i].nxt)
			if (dis[e[i].to] > dis[u] + e[i].val)
			{
				dis[e[i].to] = dis[u] + e[i].val;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
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
		SPFA(S);
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
			SPFA(S);
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