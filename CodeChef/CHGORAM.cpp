#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,T,R,f,u,v,c[MAXN],in[MAXN],out[MAXN],siz[MAXN],fa[MAXN];
long long ans;

inline int lowbit(int x){return x&-x;}
inline void add(int x){for (;x<=n;x+=lowbit(x)) ++c[x];return ;}
inline int query(int x){int r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}

inline void addedge(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline void dfs(int x,int f)
{
	in[x]=++R;fa[x]=f;siz[x]=1;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f)
		{
			dfs(e[i].to,x);
			siz[x]+=siz[e[i].to];
		}
	out[x]=R;return ;
}

inline long long solve(int x,int f)
{
	long long res,cnts=0,cntl=0;
	if (f==1) res=1LL*(n-x)*(n-x-1)/2;
	else if (f==2) res=1LL*(n-x)*(x-1);
	else res=1LL*(x-1)*(x-2)/2;
	add(in[x]);
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=fa[x])
		{
			long long s=query(out[e[i].to])-query(in[e[i].to]-1);
			long long l=siz[e[i].to]-s;
			cnts+=s;cntl+=l;
			if (f==1) res-=l*(l-1)/2;
			else if (f==2) res-=s*l;
			else res-=s*(s-1)/2;
		}
	cnts=x-cnts-1;cntl=n-cntl-x;
	if (f==1) res-=cntl*(cntl-1)/2;
	else if (f==2) res-=cnts*cntl;
	else res-=cnts*(cnts-1)/2;
	return res;
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
	read(T);
	while (T--)
	{
		memset(c,0,sizeof c);memset(head,-1,sizeof head);
		cnt=R=0;ans=0;
		read(n);read(u);read(f);read(u);
		for (int i=1;i<n;i++) read(u),read(v),addedge(u,v);
		dfs(1,-1);
		for (int i=1;i<=n;i++) ans+=solve(i,f);
		printf("%lld\n",ans);
	}
	return 0;
}