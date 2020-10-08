#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#define MAXN 5000
using namespace std;

struct link
{
	int to, flow, nxt;
};

link e[MAXN << 1];
int head[MAXN], cnt;
int dpt[MAXN];
int n, S, T, ans, a[40][40];
queue <int> q;

inline void add(int u, int v, int f) //add edge u->v
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

inline bool check(int x)
{
	cnt=1;memset(head,-1,sizeof head);S=0;T=(n+1)*(n+1);
	for (int i=1;i<=n;i++)
	{
		add(S,i,1);
		add((n+1)*n+i,T,1);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (a[i][j]>=x)
			{
				add(i,i*n+j,1);
				add(i*n+j,(n+1)*n+j,1);
			}
	int flow=0;
	while (BFS()) flow+=Dinic(S,~(1<<31));
	return flow==n;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	int l=1,r=1000000,ans;
	while (l<=r)
	{
		int mid=l+r>>1;
		if (check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}