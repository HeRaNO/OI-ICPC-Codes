#include <bits/stdc++.h>
using namespace std;

const long long mod=2009731336725594113LL;
const long long _2019=2019;
const int lim[]={4,4,8,8,8};
const int _3[]={3,3,0,1,0};
const int _4[]={5,3,3,0,1};
const long long u[]={
	314882150829468584LL,
	427197303358170108LL,
	1022292690726729920LL,
	1698479428772363217LL,
	2006101093849356424LL
};

struct SegmentTree
{
	int p,r,m,cnt,lazy[2],x[32];
};

SegmentTree tree[1<<21];
int cnt[5],n,T,l,r,las;
long long p[5][8];
long long ap[8192];

inline long long fmul(long long a,long long b)
{
	long long r=0;
	for (;b;b>>=1,(a<<=1)%=mod) if (b&1) (r+=a)%=mod;
	return r;
}

void dfs(int x,int f)
{
	if (x==5)
	{
		long long ans=1;
		for (int i=0;i<=4;i++) ans=fmul(ans,p[i][cnt[i]]);
		for (int i=0;i<=4;i++) printf("%d ",cnt[i]);
		ap[f]=ans;printf("%lld\n",ans);
		return ;
	}
	for (int i=0;i<lim[x];i++) cnt[x]=i,dfs(x+1,f<<(x<=1?2:3)|i);
	return ;
}

int test(int a,int b,int c,int d,int e)
{
	int x=a;(x<<=2)|=b;
	(x<<=3)|=c;(x<<=3)|=d;(x<<=3)|=e;
	return x;
}

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		long long a=tree[u].p;
		for (int i=0;i<32;i++)
		{
			int x=i>>3,y=i&7;
			tree[u].x[i]=fmul(fmul(p[3][x],p[4][y]),a)%_2019;
		}
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	for (int i=0;i<32;i++)
		tree[u].x[i]=tree[u<<1].x[i]+tree[u<<1|1].x[i];
	return ;
}

inline void add3(int u,int v)
{
	int x=tree[u].cnt>>3,y=tree[u].cnt&7;x+=v;
	if (x&4) y+=4,x&=3;
	y&=7;tree[u].cnt=x<<3|y;
	tree[u].lazy[0]+=v;
	if (tree[u].lazy[0]&4) tree[u].lazy[1]+=4,tree[u].lazy[0]&=3;
	tree[u].lazy[1]&=7;
	return ;
}

inline void add4(int u,int v)
{
	int x=tree[u].cnt>>3,y=tree[u].cnt&7;(y+=v)&=7;
	tree[u].cnt=x<<3|y;
	(tree[u].lazy[1]+=v)&=7;
	return ;
}

inline void PushDown(int u)
{
	if (tree[u].lazy[0])
	{
		add3(u<<1,tree[u].lazy[0]);
		add3(u<<1|1,tree[u].lazy[0]);
		tree[u].lazy[0]=0;
	}
	if (tree[u].lazy[1])
	{
		add4(u<<1,tree[u].lazy[1]);
		add4(u<<1|1,tree[u].lazy[1]);
		tree[u].lazy[1]=0;
	}
	return ;
}

void modify3(int u,int l,int r,int v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		add3(u,v);return ;
	}
	PushDown(u);
	if (r<=tree[u].m) modify3(u<<1,l,r,v);
	else if (tree[u].m<=l) modify3(u<<1|1,l,r,v);
	else
	{
		modify3(u<<1,l,tree[u].m,v);
		modify3(u<<1|1,tree[u].m,r,v);
	}
	for (int i=0;i<32;i++)
		tree[u].x[i]=tree[u<<1].x[(i+tree[u<<1].cnt)&31]+tree[u<<1|1].x[(i+tree[u<<1|1].cnt)&31];
	return ;
}

void modify4(int u,int l,int r,int v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		add4(u,v);return ;
	}
	PushDown(u);
	if (r<=tree[u].m) modify4(u<<1,l,r,v);
	else if (tree[u].m<=l) modify4(u<<1|1,l,r,v);
	else
	{
		modify4(u<<1,l,tree[u].m,v);
		modify4(u<<1|1,tree[u].m,r,v);
	}
	for (int i=0;i<32;i++)
		tree[u].x[i]=tree[u<<1].x[(i+tree[u<<1].cnt)&31]+tree[u<<1|1].x[(i+tree[u<<1|1].cnt)&31];
	return ;
}

inline int query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x[tree[u].cnt];
	PushDown(u);
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return query(u<<1,l,tree[u].m)+query(u<<1|1,tree[u].m,r);
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
	for (int i=0;i<=4;i++)
	{
		p[i][0]=1;
		for (int j=1;j<lim[i];j++) p[i][j]=fmul(p[i][j-1],u[i]);
	}
	read(n);read(T);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	/*for (int i=0;i<=4;i++)
		for (int j=0;j<lim[i];j++)
			printf("%lld%c",p[i][j],j==lim[i]-1?'\n':' ');
	dfs(0,0);*/
	while (T--)
	{
		read(l);read(r);
		printf("%d\n",las=query(1,l,r+1));las%=5;
		if (_3[las]) modify3(1,l,r+1,_3[las]);
		if (_4[las]) modify4(1,l,r+1,_4[las]);
	}
	return 0;
}
