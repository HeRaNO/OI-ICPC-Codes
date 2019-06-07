#include <bits/stdc++.h>
#define MAXN 16
using namespace std;

struct link
{
	int to;long long val;int nxt;
};

struct node
{
	long long d; int u;
	bool operator < (const node &a)const
	{
		return d > a.d;
	}
};

link e[2000000];
int head[1<<MAXN],cnt;
int n,m,k,a[MAXN],b[MAXN],sta[1<<MAXN];
long long dis[1<<MAXN],INF;
bool vis[1<<MAXN];
priority_queue <node> q;

inline void add(int u,int v,long long w)
{
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,w,head[v]};head[v]=cnt++;
}

inline void Dijkstra(int S)
{
	memset(dis,0x3f,sizeof dis); INF=dis[0];
	q.push((node){0LL, S});dis[S] = 0LL;
	while (!q.empty())
	{
		node x = q.top();
		q.pop();
		if (vis[x.u]) continue;
		vis[x.u] = true;
		for (int i = head[x.u]; ~i; i = e[i].nxt)
		{
			if (dis[e[i].to] > dis[x.u] + e[i].val)
			{
				dis[e[i].to] = dis[x.u] + e[i].val;
				q.push((node){dis[e[i].to], e[i].to});
			}
		}
	}
	return ;
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
	memset(head,-1,sizeof head);
	read(n);read(m);read(k);
	for (int i=1;i<=m;i++) read(a[i]),read(b[i]);
	for (int i=0;i<(1<<n+1);i++)
	{
		bool f=false;int rev=(1<<n+1)-i-1;
		for (int j=1;j<=m&&!f;j++)
		{
			int x=i&(1<<a[j]),y=i&(1<<b[j]);
			if (x&&y) f=true;
		}
		if (f&&!(i&1)) continue;
		f=false;
		for (int j=1;j<=m&&!f;j++)
		{
			int x=rev&(1<<a[j]),y=rev&(1<<b[j]);
			if (x&&y) f=true;
		}
		if (f&&(i&1)) continue;
		sta[++sta[0]]=i;
	}
	for (int i=1;i<=sta[0];i++)
		for (int j=i+1;j<=sta[0];j++)
		{
			int d=sta[i]^sta[j];
			if (!(d&1)) continue;
			if (sta[j]-sta[i]!=d) continue;
			int c=__builtin_popcount(d);
			if (c>k) continue;
			add(sta[i],sta[j],c);
		}
	Dijkstra((1<<n+1)-1);
	if (dis[0]==INF) puts("mole");
	else printf("%lld\n",dis[0]);
	return 0;
}