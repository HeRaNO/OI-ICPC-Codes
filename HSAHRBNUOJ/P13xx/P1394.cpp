#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 16010
#define MAXM 100010
using namespace std;

struct link
{
	int to,flow,nxt;
};

link e[MAXM<<1];
int head[MAXN],cnt;
int n,a,b,ans,S,T,c[MAXN],dpt[MAXN];
queue <int> q;
vector <int> g[MAXN];

inline int min(int a,int b){return a<b?a:b;}

inline void add(int u,int v)
{
	e[cnt]=(link){v,1,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,0,head[v]};head[v]=cnt++;
}

inline bool BFS()
{
	memset(dpt,-1,sizeof dpt);dpt[S]=1;q.push(S);
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=head[x];~i;i=e[i].nxt)
			if (e[i].flow&&!~dpt[e[i].to])
			{
				dpt[e[i].to]=dpt[x]+1;
				q.push(e[i].to);
			}
	}
	return dpt[T]!=-1;
}

int Dinic(int x,int flow)
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

void color(int x,int col)
{
	c[x]=col;
	for (int i=0;i<g[x].size();i++)
		if (!~c[g[x][i]]) color(g[x][i],col^1);
	return ;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	memset(head,-1,sizeof head);memset(c,-1,sizeof c);
	read(n);S=0;T=n+1;
	while (1){read(a);read(b);if (!a&&!b) break;g[a].push_back(b);g[b].push_back(a);}
	color(1,0);
	for (int i=1;i<=n;i++)
	{
		if (!c[i]) add(S,i);
		else add(i,T);
		for (int j=0;j<g[i].size();j++)
			if (g[i][j])
			{
				int t=g[i][j];
				if (!c[i]) add(i,t);
				else add(t,i);
				for (int k=0;k<g[t].size();k++)
					if (g[t][k]==i)
					{
						g[t][k]=0;break;
					}
			}
	}
	while (BFS()) ans+=Dinic(S,~(1<<31));
	printf("%d\n",ans);
	return 0;
}
