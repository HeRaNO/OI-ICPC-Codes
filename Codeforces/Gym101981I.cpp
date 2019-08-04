#include <bits/stdc++.h>
#define MAXN 1600
#define MAXM 500010
using namespace std;

struct link
{
	int to, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt = 1;
int dpt[MAXN];
int ans,n,m,k,S0,S1,T;
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v, int f) //add edge u->v
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
	dpt[S0] = 1;
	q.push(S0);
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
			int t = Dinic(e[i].to, mymin(left, e[i].flow));
			e[i].flow -= t;
			e[i ^ 1].flow += t;
			left -= t;
		}
	if (left) dpt[x] = -1;
	return flow - left;
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d %d %d",&n,&m,&k);
	S0=0;S1=1;T=n*2+m+2;
	add(S0,S1,k);
	for (int i=1;i<=n;i++)
	{
		add(S0,i+1,1);
		add(S1,n+i+1,1);
	}
	for (int i=1,x,p;i<=n;i++)
	{
		scanf("%d",&x);
		for (int j=1;j<=x;j++)
		{
			scanf("%d",&p);
			add(i+1,2*n+1+p,1);
			add(n+i+1,2*n+1+p,1);
		}
	}
	for (int i=1;i<=m;i++) add(2*n+1+i,T,1);
	while (BFS()) ans+=Dinic(S0,~(1<<31));
	printf("%d\n",ans );
	return 0;
}