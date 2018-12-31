#include <cstdio>
#include <cstring>
#define MAXN 100010
using namespace std;

struct link
{
	int to, nxt;
};

link e[MAXN << 1];
int head[MAXN], cnt;
int n, m, k, u, v, Cu, Cv, fu, fv, G, SIZE, T, R = -1;
int siz[MAXN], dis[MAXN], mx[MAXN], father[MAXN];
int OnCir[MAXN], Cirlen, Re[MAXN];
long long C[MAXN], ans;
bool vis[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}

inline void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, head[u]
	};
	head[u] = cnt++;
	e[cnt] = (link)
	{
		u, head[v]
	};
	head[v] = cnt++;
}

inline int lowbit(int x)
{
	return x & -x;
}

inline void modify(int x, int v)
{
	for (; x; x -= lowbit(x))
	{
		if (Re[x] != R) Re[x] = R, C[x] = 0;
		C[x] += v;
	}
	return ;
}

inline long long query(int x)
{
	long long res = 0;
	for (x = mymax(x, 1); x <= n; x += lowbit(x))
	{
		if (Re[x] != R) Re[x] = R, C[x] = 0;
		res += C[x];
	}
	return res;
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
			DFS_dis(e[i].to, x, dist + 1);
			siz[x] += siz[e[i].to];
		}
	return ;
}

inline void TreeDC(int x)
{
	vis[x] = true;
	R++;
	modify(1, 1);
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (!vis[e[i].to])
		{
			T = 0;
			DFS_dis(e[i].to, -1, 1);
			for (int i = 0; i < T; i++) ans += query(k - dis[i]);
			for (int i = 0; i < T; i++) modify(dis[i] + 1, 1);
		}
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (!vis[e[i].to])
		{
			SIZE = mx[0] = siz[e[i].to];
			G = 0;
			DFS_size_and_G(e[i].to, x);
			TreeDC(G);
		}
	vis[x] = false;
	return ;
}

inline void Normal()
{
	SIZE = mx[0] = n;
	G = 0;
	DFS_size_and_G(1, -1);
	TreeDC(G);
	return ;
}

inline void GetCircle(int x, int father)
{
	if (x == Cv)
	{
		vis[x] = true;
		OnCir[++Cirlen] = x;
		return ;
	}
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father)
		{
			GetCircle(e[i].to, x);
			if (vis[e[i].to])
			{
				OnCir[++Cirlen] = x;
				vis[x] = true;
			}
		}
	return ;
}

inline void Circle()
{
	vis[Cu] = true;
	GetCircle(Cu, -1);
	R++;
	for (int i = 1; i <= Cirlen; i++)
	{
		T = 0;
		DFS_dis(OnCir[i], -1, 1);
		for (int j = 0; j < T; j++) ans += query(k - dis[j] - Cirlen + i);
		for (int j = 0; j < T; j++) modify(dis[j] + i - 1, 1);
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
	memset(head, -1, sizeof head);
	read(n);
	read(m);
	read(k);
	if (n == m)
	{
		bool f = false;
		for (int i = 1; i <= n; i++) father[i] = i;
		for (int i = 1; i <= m; i++)
		{
			read(u);
			read(v);
			if (!f) fu = getfather(u);
			fv = getfather(v);
			if (!f && fu == fv)
			{
				Cu = u;
				Cv = v;
				f = true;
			}
			else
			{
				add(u, v);
				if (!f) father[fv] = fu;
			}
		}
	}
	else
	{
		for (int i = 1; i <= m; i++)
		{
			read(u);
			read(v);
			add(u, v);
		}
	}
	Normal();
	if (n == m) Circle();
	printf("%lld\n", ans);
	return 0;
}