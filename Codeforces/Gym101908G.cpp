#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 2005
#define MAXM 30005
using namespace std;

struct link
{
	int to, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt;
int dpt[MAXN], p, r, c;
int S, T, ans, all, d[MAXN], E[MAXN], u[MAXM], v[MAXM], t[MAXM];
queue <int> q;

inline void add(int u, int v, int f)
{
	e[++cnt] = (link){v, f, head[u]};head[u] = cnt;
	e[++cnt] = (link){u, 0, head[v]};head[v] = cnt;
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

inline bool check(int x)
{
	S=0;T=p+r+1;ans=0;
	cnt=1;memset(head,-1,sizeof head);
	for (int i=1;i<=r;i++) add(S,i,E[i]);
	for (int i=1;i<=p;i++) add(i+r,T,d[i]);
	for (int i=1;i<=c;i++) if (t[i]<=x) add(v[i],u[i]+r,~(1<<31));
	while (BFS()) ans += Dinic(S, ~(1 << 31));
	return ans==all;
}

int main()
{
	scanf("%d %d %d",&p,&r,&c);
	for (int i=1;i<=p;i++) scanf("%d",&d[i]),all+=d[i];
	for (int i=1;i<=r;i++) scanf("%d",&E[i]);
	for (int i=1;i<=c;i++) scanf("%d %d %d",&u[i],&v[i],&t[i]);
	int L=1,R=1e6,ans=-1;
	while (L<=R)
	{
		int m=L+R>>1;
		if (check(m)){ans=m;R=m-1;}
		else L=m+1;
	}
	printf("%d\n", ans);
	return 0;
}