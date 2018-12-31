#include <cstdio>
#include <cstring>
#define MAXN 5010
#define MAXM 100010
using namespace std;

struct link
{
	int to, nxt;
};

link e[MAXM];
int head[MAXN], cnt;
int n, m, u, v, in[MAXN], sta[MAXN], top, a[MAXN];

inline void add(int u, int v)
{
	in[v]++;
	e[cnt] = (link)
	{
		v, head[u]
	};
	head[u] = cnt++;
}

inline void Topological_Sort()
{
	int cnt = 0, bak;
	bool multi = false;
	for (int i = n; i; i--) if (!in[i]) sta[++top] = i;
	if (top > 1) multi = true;
	while (top)
	{
		int u = sta[top--];
		bak = top;
		a[++cnt] = u;
		for (int i = head[u]; ~i; i = e[i].nxt)
			if (--in[e[i].to] == 0) sta[++top] = e[i].to;
		if (top - bak > 1) multi = true;
	}
	if (!multi)
	{
		for (int i = 1; i <= n; i++) printf("%d\n", a[i]);
		puts("0");
	}
	else
	{
		printf("%d\n", a[1]);
		puts("1");
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
	for (int i = 1; i <= m; i++) read(u), read(v), add(u, v);
	Topological_Sort();
	return 0;
}