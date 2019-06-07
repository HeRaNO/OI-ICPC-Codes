#include <bits/stdc++.h>
#define MAXN 20010
#define MAXM 300000
using namespace std;

struct link
{
	int to, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt = 1;
int n, m, S, T, x;
long long ans;
int dpt[MAXN];
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v, int f)
{
	e[++cnt] = (link)
	{
		v, f, head[u]
	};
	head[u] = cnt;
	e[++cnt] = (link)
	{
		u, 0, head[v]
	};
	head[v] = cnt;
}

inline bool BFS()
{
	memset(dpt, -1, sizeof dpt);
	dpt[S] = 1;
	q.push(S);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nxt)
			if (e[i].flow && !~dpt[e[i].to])
			{
				dpt[e[i].to] = dpt[u] + 1;
				q.push(e[i].to);
			}
	}
	return dpt[T] != -1;
}

inline long long Dinic(int x, long long flow)
{
	long long left = flow;
	if (x == T) return flow;
	for (int i = head[x]; i && left; i = e[i].nxt)
		if (e[i].flow && dpt[e[i].to] == dpt[x] + 1)
		{
			long long t = Dinic(e[i].to, min((long long)e[i].flow, left));
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
	read(n);read(m);
	S = 0;
	T = n + m + 1;
	for (int i=1;i<=m;i++)
	{
		read(x);add(i+n,T,x);
	}
	for (int i=1;i<=n;i++)
	{
		read(x);ans+=x;add(S,i,x);
		int k,f;read(k);
		for (int j=1;j<=k;j++)
		{
			read(f);add(i,f+n,~(1<<31));
		}
	}
	while (BFS()) ans -= Dinic(S, ~(1 << 31));
	printf("%lld\n", ans);
	return 0;
}