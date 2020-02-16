#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const int M=1e9+7;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int x[1<<18][3],lazy[1<<18][3];
int T,R,n,m,o,u,v,w,a[MAXN],siz[MAXN];
int in[MAXN],top[MAXN],mx[MAXN],dep[MAXN],fa[MAXN],pos[MAXN];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline void dfs1(int x)
{
	siz[x]=1;mx[x]=-1;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=fa[x])
		{
			dep[e[i].to]=dep[x]+1;fa[e[i].to]=x;
			dfs1(e[i].to);
			siz[x]+=siz[e[i].to];
			if (!~mx[x]||siz[e[i].to]>siz[mx[x]]) mx[x]=e[i].to;
		}
	return ;
}

inline void dfs2(int x,int t)
{
	top[x]=t;pos[R]=x;in[x]=R++;
	if (~mx[x]) dfs2(mx[x],t);
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=mx[x]&&e[i].to!=fa[x]) dfs2(e[i].to,e[i].to);
	return ;
}

inline void PushUp(int u)
{
	x[u][0]=x[u<<1][0]+x[u<<1|1][0];if (x[u][0]>=M) x[u][0]-=M;
	x[u][1]=x[u<<1][1]+x[u<<1|1][1];if (x[u][1]>=M) x[u][1]-=M;
	x[u][2]=x[u<<1][2]+x[u<<1|1][2];if (x[u][2]>=M) x[u][2]-=M;
	return ;
}

// 0: +, 1: Set, 2: *

inline void Setit(int u,int l,int r,int v)
{
	int v2=1LL*v*v%M,v3=1LL*v2*v%M;
	x[u][0]=1LL*v*(r-l)%M;
	x[u][1]=1LL*v2*(r-l)%M;
	x[u][2]=1LL*v3*(r-l)%M;
	lazy[u][0]=0;lazy[u][1]=v;lazy[u][2]=1;
	return ;
}

inline int fadd(int x,int y){x+=y;if (x>=M) x-=M;return x;}

inline void addit(int u,int l,int r,int v)
{
	int v2=1LL*v*v%M,v3=1LL*v2*v%M;
	lazy[u][0]+=v;if (lazy[u][0]>=M) lazy[u][0]-=M;
	x[u][2]+=1LL*v3*(r-l)%M;if (x[u][2]>=M) x[u][2]-=M;
	x[u][2]+=3LL*v*(x[u][1]+1LL*x[u][0]*v%M)%M;if (x[u][2]>=M) x[u][2]-=M;
	x[u][1]+=fadd(1LL*v2*(r-l)%M,2LL*x[u][0]*v%M);if (x[u][1]>=M) x[u][1]-=M;
	x[u][0]+=1LL*(r-l)*v%M;if (x[u][0]>=M) x[u][0]-=M;
	return ;
}

inline void mulit(int u,int l,int r,int v)
{
	int v2=1LL*v*v%M,v3=1LL*v2*v%M;
	lazy[u][2]=1LL*lazy[u][2]*v%M;
	if (lazy[u][0]) lazy[u][0]=1LL*lazy[u][0]*v%M;
	x[u][0]=1LL*x[u][0]*v%M;
	x[u][1]=1LL*x[u][1]*v2%M;
	x[u][2]=1LL*x[u][2]*v3%M;
	return ;
}

inline void PushDown(int u,int l,int r)
{
	int m=l+r>>1;
	if (~lazy[u][1])
	{
		Setit(u<<1,l,m,lazy[u][1]);
		Setit(u<<1|1,m,r,lazy[u][1]);
		lazy[u][1]=-1;
	}
	if (lazy[u][2]!=1)
	{
		mulit(u<<1,l,m,lazy[u][2]);
		mulit(u<<1|1,m,r,lazy[u][2]);
		lazy[u][2]=1;
	}
	if (lazy[u][0])
	{
		addit(u<<1,l,m,lazy[u][0]);
		addit(u<<1|1,m,r,lazy[u][0]);
		lazy[u][0]=0;
	}
	return ;
}

inline void BuildTree(int u,int l,int r)
{
	lazy[u][0]=0;lazy[u][1]=-1;lazy[u][2]=1;
	if (l+1==r)
	{
		x[u][0]=a[pos[l]];
		x[u][1]=1LL*a[pos[l]]*a[pos[l]]%M;
		x[u][2]=1LL*a[pos[l]]*a[pos[l]]%M*a[pos[l]]%M;
		return ;
	}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	PushUp(u);
	return ;
}

inline void Set(int u,int l,int r,int v,int pl,int pr)
{
	if (l==pl&&r==pr)
	{
		Setit(u,l,r,v);
		return ;
	}
	PushDown(u,pl,pr);int m=pl+pr>>1;
	if (r<=m) Set(u<<1,l,r,v,pl,m);
	else if (m<=l) Set(u<<1|1,l,r,v,m,pr);
	else
	{
		Set(u<<1,l,m,v,pl,m);
		Set(u<<1|1,m,r,v,m,pr);
	}
	PushUp(u);
	return ;
}

inline void add(int u,int l,int r,int v,int pl,int pr)
{
	if (l==pl&&r==pr)
	{
		addit(u,l,r,v);
		return ;
	}
	PushDown(u,pl,pr);int m=pl+pr>>1;
	if (r<=m) add(u<<1,l,r,v,pl,m);
	else if (m<=l) add(u<<1|1,l,r,v,m,pr);
	else
	{
		add(u<<1,l,m,v,pl,m);
		add(u<<1|1,m,r,v,m,pr);
	}
	PushUp(u);
	return ;
}

inline void mul(int u,int l,int r,int v,int pl,int pr)
{
	if (l==pl&&r==pr)
	{
		mulit(u,l,r,v);
		return ;
	}
	PushDown(u,pl,pr);int m=pl+pr>>1;
	if (r<=m) mul(u<<1,l,r,v,pl,m);
	else if (m<=l) mul(u<<1|1,l,r,v,m,pr);
	else
	{
		mul(u<<1,l,m,v,pl,m);
		mul(u<<1|1,m,r,v,m,pr);
	}
	PushUp(u);
	return ;
}

inline int query(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return x[u][2];
	PushDown(u,pl,pr);int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else
	{
		int x=query(u<<1,l,m,pl,m);
		int y=query(u<<1|1,m,r,m,pr);
		x+=y;if (x>=M) x-=M;
		return x;
	}
}

inline void Setlink(int l,int r,int v)
{
	for (;top[l]!=top[r];l=fa[top[l]])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		Set(1,in[top[l]],in[l]+1,v,1,n+1);
	}
	if (in[l]>in[r]) swap(l,r);
	Set(1,in[l],in[r]+1,v,1,n+1);
	return ;
}

inline void addlink(int l,int r,int v)
{
	for (;top[l]!=top[r];l=fa[top[l]])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		add(1,in[top[l]],in[l]+1,v,1,n+1);
	}
	if (in[l]>in[r]) swap(l,r);
	add(1,in[l],in[r]+1,v,1,n+1);
	return ;
}

inline void mullink(int l,int r,int v)
{
	for (;top[l]!=top[r];l=fa[top[l]])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		mul(1,in[top[l]],in[l]+1,v,1,n+1);
	}
	if (in[l]>in[r]) swap(l,r);
	mul(1,in[l],in[r]+1,v,1,n+1);
	return ;
}

inline int query(int l,int r)
{
	int res=0;
	for (;top[l]!=top[r];l=fa[top[l]])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		res+=query(1,in[top[l]],in[l]+1,1,n+1);
		if (res>=M) res-=M;
	}
	if (in[l]>in[r]) swap(l,r);
	res+=query(1,in[l],in[r]+1,1,n+1);
	return res>=M?res-M:res;
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
	for (int cas=1;cas<=T;cas++)
	{
		memset(fa,0,sizeof fa);
		memset(head,-1,sizeof head);R=1;cnt=0;
		printf("Case #%d:\n",cas);
		read(n);
		for (int i=1;i<n;i++)
		{
			read(u);read(v);add(u,v);
		}
		dfs1(1);dfs2(1,1);
		for (int i=1;i<=n;i++) read(a[i]);
		BuildTree(1,1,n+1);
		read(m);
		while (m--)
		{
			read(o);read(u);read(v);
			if (o<=3) read(w);
			switch (o)
			{
				case 1:Setlink(u,v,w);break;
				case 2:addlink(u,v,w);break;
				case 3:mullink(u,v,w);break;
				case 4:printf("%d\n",query(u,v));break;
			}
		}
	}
	return 0;
}
