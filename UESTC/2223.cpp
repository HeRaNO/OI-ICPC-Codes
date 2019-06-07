#include <bits/stdc++.h>
#define MAXN 100005
#define MAXM 500005
using namespace std;

struct link
{
	int to,flow,nxt;
};

link e[MAXM<<1];
int head[MAXN], cnt = 1;
int dpt[MAXN];
int n, m, S, T, ans, a, b, u, v;
queue <int> q;

inline void add(int u, int v, int f)
{
	e[++cnt] = (link){v, f, head[u]};head[u] = cnt;
	e[++cnt] = (link){u, 0, head[v]};head[v] = cnt;
}

inline bool BFS()
{
	memset(dpt, -1, sizeof dpt);dpt[S] = 1;
	q.push(S);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = head[x]; ~i; i = e[i].nxt)
			if (e[i].flow && !~dpt[e[i].to])
			{
				dpt[e[i].to] = dpt[x] + 1;
				q.push(e[i].to);
			}
	}
	return dpt[T] != -1;
}

inline int Dinic(int x, int flow)
{
	int left = flow;
	if (x == T) return flow;
	for (int i = head[x]; ~i && left; i = e[i].nxt)
		if (e[i].flow && dpt[e[i].to] == dpt[x] + 1)
		{
			int t = Dinic(e[i].to, min(left, e[i].flow));
			e[i].flow -= t;
			e[i ^ 1].flow += t;
			left -= t;
		}
	if (left) dpt[x] = -1;
	return flow - left;
}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	memset(head, -1, sizeof head);
	read(a);read(b);read(m);
	S=0;T=a+b+1;
	for (int i=1;i<=m;i++)
	{
		read(u);read(v);
		add(u,v+a,~(1<<31));
	}
	for (int i=1;i<=a;i++) add(S,i,1);
	for (int i=1;i<=b;i++) add(i+a,T,1);
	while (BFS()) ans += Dinic(S, ~(1 << 31));
	printf("%d\n", ans);
	return 0;
}