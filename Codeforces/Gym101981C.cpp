#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,u,v,ans,siz[MAXN],a[MAXN],fa[MAXN];
bool vis[MAXN];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline pair<int,int> getCentroid(int x,bool ban)
{
	a[a[0]=1]=x;
	for (int p=1;p<=a[0];p++)
		for (int i=head[a[p]];~i;i=e[i].nxt)
			if ((!vis[e[i].to]||!ban)&&e[i].to!=fa[a[p]])
			{
				a[++a[0]]=e[i].to;
				fa[e[i].to]=a[p];
			}
	int G=0,v=n;
	for (int p=a[0];p;p--)
	{
		int x=a[p],s=0;siz[x]=1;
		for (int i=head[x];~i;i=e[i].nxt)
			if ((!vis[e[i].to]||!ban)&&e[i].to!=fa[a[p]])
			{
				siz[x]+=siz[e[i].to];
				s=max(s,siz[e[i].to]);
			}
		s=max(s,a[0]-siz[x]);
		if (s<v)
		{
			G=x;v=s;
		}
	}
	return make_pair(G,v+n-a[0]);
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d",&n);
	for (int i=1;i<n;i++) scanf("%d %d",&u,&v),add(u,v);
	int x=1;
	while (!vis[x])
	{
		pair <int,int> res=make_pair(n,-1);
		fa[x]=-1;x=getCentroid(x,true).first;
		vis[x]=true;
		for (int i=head[x];~i;i=e[i].nxt)
		{
			fa[e[i].to]=x;
			res=min(res,make_pair(getCentroid(e[i].to,false).second,e[i].to));
		}
		ans=max(ans,res.first);
		x=res.second;
	}
	printf("%d\n",ans);
	return 0;
}
