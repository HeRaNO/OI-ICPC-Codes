#include <cstdio>
#include <cstring>
#define MAXN 510
using namespace std;

struct link
{
	int to;
	int nxt;
};

link e[MAXN * MAXN];
int edge_num[MAXN << 1], cnt;
int nb, ng, m, u, v, ans;
int result[MAXN << 1], dis[MAXN << 1];
bool vis[MAXN << 1];
int q[MAXN << 1], f, r;

inline void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = cnt++;
}

bool BFS()
{
	bool flag = false;
	memset(dis, 0, sizeof dis);
	f = 1;
	r = 0;
	for (int i = 1; i <= nb; i++) if (!result[i]) dis[q[++r] = i] = 1;
	for (; f <= r; f++)
	{
		int u = q[f];
		for (int i = edge_num[u]; ~i; i = e[i].nxt)
			if (!dis[e[i].to])
			{
				dis[e[i].to] = dis[u] + 1;
				if (result[e[i].to]) dis[q[++r] = result[e[i].to]] = dis[u] + 1;
				else flag = true;
			}
	}
	return flag;
}

bool Hungary(int x)
{
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
	{
		int y = e[i].to;
		if (vis[y] || dis[x] >= dis[y]) continue;
		vis[y] = true;
		if (!result[y] || Hungary(result[y]))
		{
			result[result[x] = y] = x;
			return true;
		}
	}
	return false;
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
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	memset(edge_num, -1, sizeof edge_num);
	read(nb);
	read(ng);
	read(m);
	for (int i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		v += nb;
		add(u, v);
		if (!result[u] && !result[v])
		{
			result[result[u] = v] = u;
			ans++;
		}
	}
	while (BFS())
	{
		memset(vis, false, sizeof vis);
		for (int i = 1; i <= nb; i++) if (!result[i] && Hungary(i)) ans++;
	}
	printf("%d\n", ans);
	for (int i = 1; i <= nb; i++) printf("%d ", result[i] ? result[i] - nb : 0);
	puts("");
	return 0;
}
