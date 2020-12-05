#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct node
{
	int l,r,ls,rs,x;
	long long s;
	node(){}
	node(int _,int __):l(_),r(__),ls(0),rs(0),x(0),s(0LL){}
}tr[MAXN*20];

long long _i2[MAXN];
int n,m,T,TT,l,r,k,tot,a[MAXN],ori[MAXN],rt[MAXN];
vector <pair<int,int*> > v;

void init(int n)
{
	for (int i=1;i<=n;i++) _i2[i]=_i2[i-1]+1LL*i*i;
	return ;
}

inline int Build(int l,int r)
{
	int p=++tot;tr[p]=node(l,r);
	if (l==r) return p;
	int m=l+r>>1;
	tr[p].ls=Build(l,m);tr[p].rs=Build(m+1,r);
	return p;
}

int add(int x,int v,int now)
{
	int p=++tot;tr[p]=tr[now];tr[p].s+=v;++tr[p].x;
	if (tr[p].l==tr[p].r) return p;
	int m=tr[p].l+tr[p].r>>1;
	if (x<=m) tr[p].ls=add(x,v,tr[p].ls);
	else tr[p].rs=add(x,v,tr[p].rs);
	return p;
}

inline long long query(int ls,int rs,int k,int pl,int pr)
{
	if (pl==pr) return 1LL*k*ori[pl];
	int x=tr[tr[rs].rs].x-tr[tr[ls].rs].x;
	int m=pl+pr>>1;
	if (k<=x) return query(tr[ls].rs,tr[rs].rs,k,m+1,pr);
	else return query(tr[ls].ls,tr[rs].ls,k-x,pl,m)+tr[tr[rs].rs].s-tr[tr[ls].rs].s;
}

inline void Solve()
{
	v.clear();v.push_back({-1,NULL});tot=T=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),v.push_back({a[i],&a[i]});
	sort(v.begin(),v.end());
	for (int i=1;i<=n;i++)
	{
		if (v[i].first!=v[i-1].first) ori[++T]=v[i].first;
		*v[i].second=T;
	}
	rt[0]=Build(1,T);
	for (int i=1;i<=n;i++) rt[i]=add(a[i],ori[a[i]],rt[i-1]);
	scanf("%d",&m);
	while (m--)
	{
		scanf("%d %d %d",&l,&r,&k);
		printf("%lld\n",query(rt[l-1],rt[r],k,1,T)+_i2[r-l+1]);
	}
	return ;
}


int main()
{
	init(100000);
	scanf("%d",&TT);
	while (TT--) Solve();
	return 0;
}