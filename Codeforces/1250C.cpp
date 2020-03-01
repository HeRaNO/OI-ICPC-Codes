#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<ll,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int N=200050;
int n;ll k;
ll s[N];
struct segment
{
	ll l,r,v,id;
}p[N];
struct segtree
{
	int l,r;
	ll lazy;
	pii v;
}t[N<<2];
inline bool cmp(const segment &x,const segment &y)
{
	return x.l<y.l||(x.l==y.l&&x.r<y.r);
}
inline void pushup(int id)
{
	t[id].v=max(t[ls].v,t[rs].v);
}
inline void pushdown(int id)
{
	if(t[id].lazy)
	{
		t[ls].v.first+=t[id].lazy;
		t[rs].v.first+=t[id].lazy;
		t[ls].lazy+=t[id].lazy;
		t[rs].lazy+=t[id].lazy;
		t[id].lazy=0;
	}
}
void build(int l,int r,int id)
{
	t[id].l=l,t[id].r=r;
	if(l==r)
	{
		t[id].v.first=s[l];
		t[id].v.second=l;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	pushup(id);
}
void change(int l,int r,int id,int L,int R,ll v)
{
	if(l>=L&&R>=r)
	{
		t[id].v.first+=v;
		t[id].lazy+=v;
		return;
	}
	pushdown(id);
	int mid=(l+r)>>1;
	if(R<=mid)change(l,mid,ls,L,R,v);
	else if(L>mid)change(mid+1,r,rs,L,R,v);
	else
	{
		change(l,mid,ls,L,mid,v);
		change(mid+1,r,rs,mid+1,R,v);
	}
	pushup(id);
}
ll tmp;int pos;
pii query(int l,int r,int id,int L,int R)
{
	if(l>=L&&R>=r)return t[id].v;
	pushdown(id);
	int mid=(l+r)>>1;
	if(R<=mid)return query(l,mid,ls,L,R);
	else if(L>mid)return query(mid+1,r,rs,L,R);
	else return max(query(l,mid,ls,L,mid),query(mid+1,r,rs,mid+1,R));
}
vector <int> work;

int main()
{
	cin>>n>>k;
	ll L=0,R=0;
	for(int i=1;i<=n;++i)
	{
		ll l,r,val;
		scanf("%lld%lld%lld",&l,&r,&val);
		p[i].id=i;
		p[i].l=l,p[i].r=r,p[i].v=val;
		s[r]+=val;
	}
	for(int i=1;i<=200000;++i)s[i]-=k;
	for(int i=1;i<=200000;++i)s[i]+=s[i-1];
	sort(p+1,p+n+1,cmp);
	build(1,200000,1);
	ll ans=0;
	int j=1;
	for(int i=1;i<=200000;++i)
	{
		while(j<=n&&p[j].l<i)
		{
			change(1,200000,1,p[j].r,200000,-p[j].v);
			j++;
		}
		pii tmp=query(1,200000,1,i,200000);
		if(tmp.first+k*(1LL*i-1LL)>ans)
		{
			ans=tmp.first+k*(1LL*i-1LL);
			L=i,R=tmp.second;
		}
	}
	if(ans<=0)return puts("0"),0;
	printf("%lld %lld %lld ",ans,L,R);
	for(int i=1;i<=n;++i)
	{
		if(p[i].l>=L&&p[i].r<=R)work.push_back(p[i].id);
	}
	printf("%d\n",work.size());
	for(auto i:work)printf("%d ",i);
	puts("");
	return 0;
}
