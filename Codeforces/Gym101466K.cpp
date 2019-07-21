#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

const long long p[]={0,2,3,5,7,11,13};
const long long M=1e9+7;

struct link
{
	int to,nxt;
};

struct data
{
	long long cnt[7];
	data(){}
	data operator + (const data &a)const{
		data res;
		for (int i=1;i<=6;i++) res.cnt[i]=cnt[i]+a.cnt[i];
		return res;
	}	
};

struct SegmentTree
{
	int p,r,m;data w;
};

link e[MAXN<<1];
int head[MAXN],cnt,rev[MAXN];
SegmentTree tree[1<<18];
int n,T,R=1,u,x,v,in[MAXN],out[MAXN],a[MAXN];
char o[10];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;a=(a*a)%M,b>>=1) if (b&1) r=(r*a)%M;
	return r;
}

void dfs(int x,int f)
{
	rev[R]=x;in[x]=R++;
	for (int i=head[x];~i;i=e[i].nxt) if (e[i].to!=f) dfs(e[i].to,x);
	out[x]=R;
	return ;
}

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		int x=a[rev[tree[u].p]];int pt=1;
		while (x!=1)
		{
			if (!(x%p[pt]))
			{
				while (!(x%p[pt])){++tree[u].w.cnt[pt];x/=p[pt];}
			}
			++pt;
		}
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].w=tree[u<<1].w+tree[u<<1|1].w;
	return ;
}

inline void modify(int u,int x,int v)
{
	if (tree[u].p+1==tree[u].r)
	{
		int x=v;int pt=1;
		while (x!=1)
		{
			if (!(x%p[pt]))
			{
				while (!(x%p[pt])){++tree[u].w.cnt[pt];x/=p[pt];}
			}
			++pt;
		}
		return ;
	}
	if (x<tree[u].m) modify(u<<1,x,v);
	else modify(u<<1|1,x,v);
	tree[u].w=tree[u<<1].w+tree[u<<1|1].w;
	return ;
}

inline data query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].w;
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return query(u<<1,l,tree[u].m)+query(u<<1|1,tree[u].m,r);
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='R')
		{
			getchar();getchar();getchar();
			x=0;return ;
		}
		if (ch=='S')
		{
			getchar();getchar();getchar();
			x=1;return ;
		}
	}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d",&n);
	for (int i=1;i<n;i++) scanf("%d %d",&u,&v),add(u+1,v+1);
	dfs(1,-1);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s %d",o,&x);
		++x;
		if (o[0]=='R')
		{
			data pp=query(1,in[x],out[x]);
			long long ans1=1,ans2=1;
			for (int i=1;i<=6;i++)
			{
				ans1=(ans1*fpow(p[i],pp.cnt[i]))%M;
				(ans2*=(pp.cnt[i]+1))%=M;
			}
			printf("%lld %lld\n",ans1,ans2);
		}
		else
		{
			scanf("%d",&v);
			modify(1,in[x],v);
		}
	}
	return 0;
}