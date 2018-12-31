#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#define MAXN 10010
#define MAXM 20010
using namespace std;

struct link
{
	int to, nxt;
};

struct way
{
	int x, y, z, t;
	way() {}
	way(int _x, int _y, int _z, int _t): x(_x), y(_y), z(_z), t(_t) {}
};

link e[MAXM << 1];
int head[MAXN], cnt;
int n, m, L, x, y, S, T, tar, tar2;
bool vis[MAXN];
vector <way> c[MAXN];

inline void add(int x, int y)
{
	e[cnt] = (link)
	{
		y, head[x]
	};
	head[x] = cnt++;
	e[cnt] = (link)
	{
		x, head[y]
	};
	head[y] = cnt++;
}

void dfs1(int x, int f, int len, int x1, int x2, int x3, int x4)
{
	if (vis[x]) return ;
	vis[x] = true;
	if (!x1) x1 = x;
	else if (!x2) x2 = x;
	else if (!x3) x3 = x;
	else x4 = x;
	if (x == T && len != tar)
	{
		vis[x] = false;
		return ;
	}
	if (len == tar)
	{
		c[x].push_back(way(x1, x2, x3, x4));
		vis[x] = false;
		return ;
	}
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != f) dfs1(e[i].to, x, len + 1, x1, x2, x3, x4);
	vis[x] = false;
	return ;
}

void dfs2(int x, int f, int len, int x1, int x2, int x3, int x4)
{
	if (vis[x]) return ;
	vis[x] = true;
	if (!x1) x1 = x;
	else if (!x2) x2 = x;
	else if (!x3) x3 = x;
	else x4 = x;
	if (x == S && len != tar2)
	{
		vis[x] = false;
		return ;
	}
	if (len == tar2)
	{
		if (c[x].size())
		{
			for (int i = 0; i < c[x].size(); i++)
			{
				int fl = 0;
				if (c[x][i].x)
				{
					if (c[x][i].x == x1) ++fl;
					if (c[x][i].x == x2) ++fl;
					if (c[x][i].x == x3) ++fl;
					if (c[x][i].x == x4) ++fl;
				}
				if (c[x][i].y)
				{
					if (c[x][i].y == x1) ++fl;
					if (c[x][i].y == x2) ++fl;
					if (c[x][i].y == x3) ++fl;
					if (c[x][i].y == x4) ++fl;
				}
				if (c[x][i].z)
				{
					if (c[x][i].z == x1) ++fl;
					if (c[x][i].z == x2) ++fl;
					if (c[x][i].z == x3) ++fl;
					if (c[x][i].z == x4) ++fl;
				}
				if (c[x][i].t)
				{
					if (c[x][i].t == x1) ++fl;
					if (c[x][i].t == x2) ++fl;
					if (c[x][i].t == x3) ++fl;
					if (c[x][i].t == x4) ++fl;
				}
				if (fl == 1)
				{
					puts("YES");
					exit(0);
				}
			}
		}
		vis[x] = false;
		return ;
	}
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != f) dfs2(e[i].to, x, len + 1, x1, x2, x3, x4);
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
	memset(head, -1, sizeof head);
	read(n);
	read(m);
	read(L);
	tar = L >> 1;
	tar2 = L - tar;
	for (int i = 1; i <= m; i++)
	{
		read(x);
		read(y);
		add(x, y);
	}
	read(S);
	read(T);
	dfs1(S, -1, 0, 0, 0, 0, 0);
	dfs2(T, -1, 0, 0, 0, 0, 0);
	puts("NO");
	return 0;
}
