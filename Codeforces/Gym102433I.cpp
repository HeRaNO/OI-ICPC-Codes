#include <bits/stdc++.h>
#define MAXN 1005
#define MAXM 300005
using namespace std;

struct link
{
	int to, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt = 1;
int dpt[MAXN];
int n, l, S, T, ans;
queue <int> q;
char s[MAXN>>1][30];

inline void addedge(int u, int v, int f) //add edge u->v
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

inline void add(int u,int v)
{
	addedge(u,v+n,1);addedge(v,u+n,1);
	return ;
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
	memset(head,-1,sizeof head);
	scanf("%d",&n);T=n<<1|1;
	for (int i=1;i<=n;i++) scanf("%s",s[i]);
	l=strlen(s[1]);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			int cnt=0;
			for (int k=0;k<l;k++)
				cnt+=(s[i][k]!=s[j][k]);
			if (cnt<=2) add(i,j);
		}
	for (int i=1;i<=n;i++) addedge(S,i,1),addedge(i+n,T,1);
	while (BFS()) ans+=Dinic(S,~(1<<31));
	printf("%d\n",n-(ans+1)/2);
	return 0;
}