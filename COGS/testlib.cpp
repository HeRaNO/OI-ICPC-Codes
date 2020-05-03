#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 1030
#define MAXM 30000
using namespace std;

struct link
{
	int to,flow,nxt;
};

link e[MAXM<<1];
int head[MAXN],cnt=1;
int n,k,S,T,x,y,ans,sum;
int dpt[MAXN];
queue <int> q;

inline int mymin(int a,int b){return a<b?a:b;}

inline void add(int u,int v,int f)
{
	e[++cnt]=(link){v,f,head[u]};head[u]=cnt;
	e[++cnt]=(link){u,0,head[v]};head[v]=cnt;
}

inline bool BFS()
{
	memset(dpt,-1,sizeof dpt);dpt[S]=1;
	q.push(S);
	while (!q.empty())
	{
		int u=q.front();q.pop();
		for (int i=head[u];i;i=e[i].nxt)
			if (e[i].flow&&!~dpt[e[i].to])
			{
				dpt[e[i].to]=dpt[u]+1;
				q.push(e[i].to);
			}
	}
	return dpt[T]!=-1;
}

inline int Dinic(int x,int flow)
{
	int left=flow;
	if (x==T) return flow;
	for (int i=head[x];i&&left;i=e[i].nxt)
		if (e[i].flow&&dpt[e[i].to]==dpt[x]+1)
		{
			int t=Dinic(e[i].to,mymin(e[i].flow,left));
			e[i].flow-=t;e[i^1].flow+=t;left-=t;
		}
	if (left) dpt[x]=-1;
	return flow-left;
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
	freopen("testlib.in","r",stdin);freopen("testlib.out","w",stdout);
	read(k);read(n);S=0;T=n+k+1;
	for (int i=1;i<=k;i++)
	{
		read(x);sum+=x;
		add(S,i,x);
	}
	for (int i=1;i<=n;i++)
	{
		read(x);add(i+k,T,1);
		while (x--)
		{
			read(y);
			add(y,i+k,1);
		}
	}
	while (BFS()) ans+=Dinic(S,~(1<<31));
	if (ans==sum)
	{
		for (int i=1;i<=k;i++,puts(""))
		{
			printf("%d:",i);
			for (int j=head[i];j;j=e[j].nxt)
				if (e[j^1].flow) printf(" %d",e[j].to-k);
		}
	}
	else puts("NoSolution!");
	return 0;
}