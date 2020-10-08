#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct Seg
{
	int l,r,y,d;
	Seg(){}
	Seg(int _l,int _r,int _y,int _d):l(_l),r(_r),y(_y),d(_d){}
	bool operator < (const Seg &a)const{
		return y<a.y;
	}
};

vector <Seg> a;
long long l[3][1<<19];
int cnt[1<<19],lazy[1<<19];
int n,m,p,q,r,s,x[MAXN<<1],ori[MAXN<<1];
long long ans;
unordered_map <int,int> h;

void Build(int u,int p,int r)
{
	if (p+1==r)
	{
		l[0][u]=l[2][u]=ori[r]-ori[p];
		return ;
	}
	int m=p+r>>1;Build(u<<1,p,m);Build(u<<1|1,m,r);
	l[0][u]=l[0][u<<1]+l[0][u<<1|1];
	l[2][u]=l[2][u<<1]+l[2][u<<1|1];
	return ;
}

inline void add(int u,int v)
{
	lazy[u]+=v;cnt[u]+=v;
	if (abs(v)&1) swap(l[0][u],l[1][u]);
	return ;
}

inline void PushDown(int u)
{
	if (!lazy[u]) return ;
	add(u<<1,lazy[u]);add(u<<1|1,lazy[u]);
	lazy[u]=0;return ;
}

inline void PushUp(int u)
{
	l[0][u]=l[0][u<<1]+l[0][u<<1|1];
	l[1][u]=l[1][u<<1]+l[1][u<<1|1];
	int x=cnt[u<<1]>cnt[u<<1|1];
	cnt[u]=cnt[u<<1|x];l[2][u]=l[2][u<<1|x];
	if (cnt[u<<1]==cnt[u<<1|1])
		l[2][u]=l[2][u<<1]+l[2][u<<1|1];
	return ;
}

void modify(int u,int l,int r,int v,int pl,int pr)
{
	if (pl==l&&pr==r){add(u,v);return ;}
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) modify(u<<1,l,r,v,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,v,m,pr);
	else
	{
		modify(u<<1,l,m,v,pl,m);
		modify(u<<1|1,m,r,v,m,pr);
	}
	PushUp(u);
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&p,&q,&r,&s);
		if (p==r||q==s) continue;
		a.emplace_back(min(p,r),max(p,r),min(q,s), 1);
		a.emplace_back(min(p,r),max(p,r),max(q,s),-1);
		x[++x[0]]=p;x[++x[0]]=r;
	}
	if (!x[0]) return puts("0"),0;
	sort(x+1,x+x[0]+1);
	sort(a.begin(),a.end());
	h[x[1]]=++m;ori[m]=x[1];
	for (int i=2;i<=x[0];i++)
	{
		if (x[i]!=x[i-1]) ++m;
		h[x[i]]=m;ori[m]=x[i];
	}
	Build(1,1,m);
	for (int i=0;i+1<a.size();i++)
	{
		if (h[a[i].l]<h[a[i].r]) modify(1,h[a[i].l],h[a[i].r],a[i].d,1,m);
		ans+=(l[0][1]-(!cnt[1])*l[2][1])*(a[i+1].y-a[i].y);
	}
	printf("%lld\n",ans);
	return 0;
}