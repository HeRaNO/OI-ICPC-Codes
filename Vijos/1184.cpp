#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct Trie
{
	int son[256], id, w;
};

struct link
{
	int to, val, nxt;
};

struct node
{
	int d, u;
	bool operator < (const node &a)const
	{
		return d > a.d;
	}
};

Trie tree[MAXN << 2];
link e[MAXN << 1];
int head[MAXN], cnt;
int n, m, u, v, w, ip[4], iph[MAXN][4], top, root, id;
int dis[MAXN];
bool flag;
priority_queue <node> q;
pair <int, int> p[MAXN];

inline int newnode()
{
	memset(tree[top].son, -1, sizeof tree[top].son);
	tree[top++].id = -1;
	return top - 1;
}

inline void add(int x)
{
	int now = root;
	for (int i = 0; i < 4; i++)
	{
		if (!~tree[now].son[ip[i]]) tree[now].son[ip[i]] = newnode();
		now = tree[now].son[ip[i]];
	}
	if (!~tree[now].id)
	{
		tree[now].id = ++id;
		flag = true;
	}
	tree[now].w += x;
	return ;
}

inline int query()
{
	int now = root;
	for (int i = 0; i < 4; i++) now = tree[now].son[ip[i]];
	w += tree[now].w;
	return tree[now].id;
}

inline void add(int u, int v, int w)
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

inline int Dijkstra(int S)
{
	for (int i = 1; i <= n; i++) dis[i] = ~(1 << 31);
	q.push((node)
	{
		0, S
	});
	dis[S] = 0;
	while (!q.empty())
	{
		node x = q.top();
		q.pop();
		for (int i = head[x.u]; ~i; i = e[i].nxt)
			if (dis[e[i].to] > dis[x.u] + e[i].val)
			{
				dis[e[i].to] = dis[x.u] + e[i].val;
				q.push((node)
				{
					dis[e[i].to], e[i].to
				});
			}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dis[i] == ~(1 << 31)) return dis[i];
		ans += dis[i];
	}
	return ans;
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
	memset(head, -1, sizeof head);
	read(n);
	root = newnode();
	for (int i = 1; i <= n; i++, flag = false)
	{
		for (int j = 0; j < 4; j++) read(ip[j]);
		read(w);
		add(w);
		if (flag) for (int j = 0; j < 4; j++) iph[id][j] = ip[j];
	}
	n = id;
	read(m);
	w = 0;
	for (int i = 1; i <= m; i++, w = 0)
	{
		for (int j = 0; j < 4; j++) read(ip[j]);
		u = query();
		for (int j = 0; j < 4; j++) read(ip[j]);
		v = query();
		if (~u && ~v) add(u, v, w);
	}
	for (int i = 1; i <= n; i++) p[i] = make_pair(Dijkstra(i), i);
	sort(p + 1, p + n + 1);
	if (p[n].first == ~(1 << 31) || p[n].first == p[n - 1].first)
		puts("The ONLY truth is: it is you, 222.240.168.135");
	else
	{
		printf("The ONLY truth is: it is you, ");
		printf("%d", iph[p[n].second][0]);
		for (int i = 1; i <= 3; i++) printf(".%d", iph[p[n].second][i]);
		puts("");
	}
	return 0;
}