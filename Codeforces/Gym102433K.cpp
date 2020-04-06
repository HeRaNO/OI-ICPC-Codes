#include <bits/stdc++.h>
#define MAXN 500005
#define fi first
#define se second
using namespace std;

struct BIT
{
	int n;
	vector <int> c;
	BIT(){}
	void init(int _n){n=_n;c.resize(n+1,0);}
	int lowbit(int x){return x&-x;}
	void modifyA(int x)
	{
		for (;x<=n;x+=lowbit(x)) (++c[x])&=255;
		return ;
	}
	void modifyB(int x)
	{
		for (;x<=n;x+=lowbit(x)) (c[x]+=255)&=255;
		return ;
	}
	void modify(int l,int r)
	{
		modifyA(l);modifyB(r+1);
		return ;
	}
	int query(int x)
	{
		int r=0;
		for (;x;x-=lowbit(x)) (r+=c[x])&=255;
		return r;
	}
};

struct Query
{
	int a,b,c,d;
	Query(){}
	Query(int _a,int _b,int _c,int _d):
		a(_a),b(_b),c(_c),d(_d){}
	bool operator < (const Query &p)const{
		return a<p.a;
	}
};

BIT s[MAXN];
pair <int,int> tree[1<<20];
int n,m,q,x,y,z,o,ans[MAXN],cnt,pos[MAXN];
vector <int> a[MAXN];
vector <Query> Q;

inline void modify(int u,int l,int r,pair<int,int> v,int pl,int pr)
{
	if (l==pl&&r==pr){tree[u]=v;return ;}
	int m=pl+pr>>1;
	if (r<=m) modify(u<<1,l,r,v,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,v,m,pr);
	else
	{
		modify(u<<1,l,m,v,pl,m);
		modify(u<<1|1,m,r,v,m,pr);
	}
	return ;
}

inline pair<int,int> query(int x)
{
	int u=1,l=1,r=n+1;pair <int,int> res(0,0);
	while (l+1!=r)
	{
		res=max(res,tree[u]);
		int m=l+r>>1;u<<=1;
		if (x<m) r=m;
		else{u|=1;l=m;}
	}
	return max(res,tree[u]);
}

int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&x);s[i].init(x);
		for (int j=1;j<=x;j++)
		{
			scanf("%d",&y);
			a[i].emplace_back(y);
		}
	}
	for (int i=1;i<=q;i++)
	{
		scanf("%d",&o);
		if (o==1)
		{
			scanf("%d %d",&x,&y);pos[i]=y;
			modify(1,y,y+a[x].size(),{i,x},1,n+1);
		}
		else if (o==2)
		{
			scanf("%d",&x);++cnt;
			pair <int,int> r=query(x);
			if (!r.fi) continue;
			Q.emplace_back(Query(r.fi,r.se,x-pos[r.fi],-cnt));
		}
		else
		{
			scanf("%d %d %d",&x,&y,&z);
			Q.emplace_back(Query(i,x,y,z));
		}
	}
	sort(Q.begin(),Q.end());
	for (auto x:Q)
	{
		if (x.d<0)
		{
			ans[-x.d]=a[x.b][x.c]+s[x.b].query(x.c+1);
			ans[-x.d]&=255;
		}
		else s[x.b].modify(x.c,x.d);
	}
	for (int i=1;i<=cnt;i++) printf("%d\n",ans[i]);
	return 0;
}