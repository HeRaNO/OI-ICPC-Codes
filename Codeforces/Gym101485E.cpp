#include <bits/stdc++.h>
#define MAXN 10005
#define MAXM 20000
using namespace std;

struct link
{
	int to, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt = 1;
int dpt[MAXN];
int n, m, S, T, ans, p[MAXN][3];
int u[MAXN], v[MAXN];
pair <long long,int*> b[MAXN];
queue <int> q;
long long ori[MAXN];

inline void add(int u, int v, int f)
{
	e[++cnt] = (link){ v, f, head[u] }; head[u] = cnt;
	e[++cnt] = (link){ u, 0, head[v] }; head[v] = cnt;
}

inline bool BFS()
{
	memset(dpt, -1, sizeof dpt);
	dpt[S] = 1;
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

int main()
{
	memset(head, -1, sizeof head);
	scanf("%d",&n);b[0].first=1LL<<63;
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&u[i],&v[i]);
		b[(i-1)*3+1]={u[i]+v[i],&p[i][0]};
		b[(i-1)*3+2]={u[i]-v[i],&p[i][1]};
		b[i*3]={1LL*u[i]*v[i],&p[i][2]};
	}
	sort(b+1,b+3*n+1);
	for (int i=1;i<=3*n;i++)
	{
		if (b[i].first!=b[i-1].first) ori[++m]=b[i].first;
		*b[i].second=m;
	}
	T=n+m+1;
	for (int i=1;i<=n;i++) add(S,i,1);
	for (int i=1;i<=m;i++) add(i+n,T,1);
	for (int i=1;i<=n;i++)
	{
		add(i,n+p[i][0],1);
		add(i,n+p[i][1],1);
		add(i,n+p[i][2],1);
	}
	while (BFS()) ans += Dinic(S, ~(1 << 31));
	if (ans!=n) return puts("impossible");
	for (int i=1;i<=n;i++)
		for (int j=head[i];~j;j=e[j].nxt)
			if (e[j].to>n&&!e[j].flow)
			{
				if (p[i][0]+n==e[j].to) printf("%d + %d = %d\n", u[i], v[i], u[i] + v[i]);
				else if (p[i][1]+n==e[j].to) printf("%d - %d = %d\n", u[i], v[i], u[i] - v[i]);
				else printf("%d * %d = %lld\n", u[i], v[i], 1LL * u[i] * v[i]);
			}
	return 0;
}