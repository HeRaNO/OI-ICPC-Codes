#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,m,o[MAXN],x[MAXN],ori[MAXN],cnt[MAXN];
pair <int,int*> b[MAXN];
multiset <int> s;

struct H
{
	int mx,mn,dif;
	H(){}
	H(int _mx,int _mn,int _dif):mx(_mx),mn(_mn),dif(_dif){}
	H operator + (const H &a)const{
		H res;
		res.mx=max(mx,a.mx);res.mn=min(mn,a.mn);
		res.dif=min(dif,a.dif);
		if (mx!=1<<31&&a.mn!=~(1<<31))
			res.dif=min(res.dif,ori[a.mn]-ori[mx]);
		return res;
	}
}t[1<<19];

inline void BuildTree(int u,int l,int r)
{
	t[u]=H(1<<31,~(1<<31),~(1<<31));
	if (l+1==r) return ;
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	return ;
}

inline void add(int u,int x,int l,int r)
{
	if (l+1==r)
	{
		t[u]=H(l,l,~(1<<31));++cnt[l];
		if (cnt[l]>=2) t[u].dif=0;
		return ;
	}
	int m=l+r>>1;
	if (x<m) add(u<<1,x,l,m);
	else add(u<<1|1,x,m,r);
	t[u]=t[u<<1]+t[u<<1|1];
	return ;
}

inline void del(int u,int x,int l,int r)
{
	if (l+1==r)
	{
		--cnt[l];
		if (cnt[l]>=2) t[u]=H(l,l,0);
		else if (cnt[l]) t[u]=H(l,l,~(1<<31));
		else t[u]=H(1<<31,~(1<<31),~(1<<31));
		return ;
	}
	int m=l+r>>1;
	if (x<m) del(u<<1,x,l,m);
	else del(u<<1|1,x,m,r);
	t[u]=t[u<<1]+t[u<<1|1];
	return ;
}

inline H query(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return t[u];
	int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else return query(u<<1,l,m,pl,m)+query(u<<1|1,m,r,m,pr);
}

inline void A(int x)
{
	s.insert(ori[x]);add(1,x,1,m+1);
	return ;
}

inline void D(int x)
{
	s.erase(s.find(ori[x]));del(1,x,1,m+1);
	return ;
}

inline bool checkBig(int x)
{
	x=ori[x];int a,b;
	s.insert(x);
	auto it=s.upper_bound(x);
	if (it==s.begin())
	{
		s.erase(s.find(x));
		return false;
	}
	--it;
	if (it==s.begin())
	{
		s.erase(s.find(x));
		return false;
	}
	--it;a=*it;
	if (it==s.begin())
	{
		s.erase(s.find(x));
		return false;
	}
	--it;b=*it;
	s.erase(s.find(x));
	return a+b>x;
}

inline bool checkSmall(int x)
{
	return ori[x]>query(1,x,m+1,1,m+1).dif;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d %d",&o[i],&x[i]),b[i]={x[i],&x[i]};
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++)
	{
		if (b[i].first!=b[i-1].first) ori[++m]=b[i].first;
		*b[i].second=m;
	}
	BuildTree(1,1,m+1);
	for (int i=1;i<=n;i++)
	{
		if (o[i]==1) A(x[i]);
		else if (o[i]==2) D(x[i]);
		else
		{
			if (checkBig(x[i])||checkSmall(x[i])) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}