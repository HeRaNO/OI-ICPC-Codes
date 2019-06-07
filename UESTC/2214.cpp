#include <bits/stdc++.h>
#define MAXM 200010
#define MAXN 200010
using namespace std;

struct edge{int x,y,z;};
struct link{int to,nxt;};

edge g[MAXM];
link e[MAXM];
int head[MAXN],cnt,in[MAXN],sta[MAXN],top;
int n,m;
long long l=~(1LL<<63),r=-1LL,ans=-1LL,mid;

inline void add(int u,int v)
{
	++in[v];e[cnt]=(link){v,head[u]};head[u]=cnt++;
	return ;
}

inline bool ok(long long x)
{
	memset(in,0,sizeof in);memset(head,-1,sizeof head);cnt=0;top=0;
	for (int i=1;i<=m;i++) if ((long long)g[i].z>x) add(g[i].x,g[i].y);
	for (int i=1;i<=n;i++) if (!in[i]) sta[++top]=i;
	while (top)
	{
		int u=sta[top--];
		for (int i=head[u];~i;i=e[i].nxt)
			if (--in[e[i].to]==0) sta[++top]=e[i].to;
	}
	for (int i=1;i<=n;i++) if (in[i]) return false;
	return true;
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
	for (int i=1;i<=m;i++)
	{
		read(g[i].x);read(g[i].y);read(g[i].z);
		l=min(l,(long long)g[i].z);r=max(r,(long long)g[i].z);
	}
	while (l<=r)
	{
		mid=l+r>>1;
		if (ok(mid)){ans=mid;r=mid-1;}
		else l=mid+1;
	}
	if (!~ans) puts("Sleep forever!");
	else printf("%lld\n",ans);
	return 0;
}