#pragma GCC optimize("O2")
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10005
using namespace std;

struct link
{
	int to, val, nxt;
};

link e[MAXN << 1];
int head[MAXN], cnt;
int n, k, v, w, T, SIZE, G, ans;
int dis[MAXN], siz[MAXN], mx[MAXN];
bool vis[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
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

inline void DFS_size_and_G(int x, int father)
{
	siz[x] = 1;
	mx[x] = 0;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father && !vis[e[i].to])
		{
			DFS_size_and_G(e[i].to, x);
			siz[x] += siz[e[i].to];
			mx[x] = mymax(mx[x], siz[e[i].to]);
		}
	mx[x] = mymax(mx[x], SIZE - siz[x]);
	if (mx[x] < mx[G]) G = x;
	return ;
}

inline void DFS_dis(int x, int father, int dist)
{
	dis[T++] = dist;
	siz[x] = 1;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father && !vis[e[i].to])
		{
			DFS_dis(e[i].to, x, dist + e[i].val);
			siz[x] += siz[e[i].to];
		}
	return ;
}

inline int Calculate(int x, int dist)
{
	T = 0;
	DFS_dis(x, -1, dist);
	sort(dis, dis + T);
	int res = 0, L = 0, R = T - 1;
	while (L < R)
	{
		while (dis[L] + dis[R] > k && L < R) R--;
		if (dis[L] + dis[R] == k)
		{
			if (dis[L] == dis[R])
			{
				res += (R - L + 1) * (R - L) >> 1;
				break;
			}
			int i = L, j = R, cntl = 0, cntr = 0;
			while (dis[i] == dis[L]) i++, cntl++;
			while (dis[j] == dis[R]) j--, cntr++;
			res += cntl * cntr;
			L = i;
			R = j;
		}
		else L++;
	}
	return res;
}

inline void TreeDC(int x)
{
	ans += Calculate(x, 0);
	vis[x] = true;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (!vis[e[i].to])
		{
			ans -= Calculate(e[i].to, e[i].val);
			mx[0] = SIZE = siz[e[i].to];
			G = 0;
			DFS_size_and_G(e[i].to, x);
			TreeDC(G);
		}
	vis[x] = false;
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
	while (true)
	{
		read(n);
		if (!n) break;
		memset(head, -1, sizeof head);
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			while (true)
			{
				read(v);
				if (!v) break;
				read(w);
				add(i, v, w);
			}
		}
		while (true)
		{
			read(k);
			if (!k) break;
			SIZE = mx[0] = n;
			G = 0;
			DFS_size_and_G(1, -1);
			ans = 0;
			TreeDC(G);
			if (ans) puts("AYE");
			else puts("NAY");
			ans = 0;
		}
		puts(".");
	}
	return 0;
}