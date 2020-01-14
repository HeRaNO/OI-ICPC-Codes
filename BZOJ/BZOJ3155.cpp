#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,m,o,v,p,a[MAXN];
long long s[MAXN],x[1<<18],lazy[1<<18];

inline void BuildTree(int u,int l,int r)
{
	if (l+1==r){x[u]=s[l];return ;}
	int m=l+r>>1;
	BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	x[u]=x[u<<1]+x[u<<1|1];
	return ;
}

inline void add(int u,int l,int r,int v)
{
	x[u]+=1LL*(r-l)*v;lazy[u]+=v;
	return ;
}

inline void PushDown(int u,int l,int r)
{
	if (!lazy[u]) return ;int m=l+r>>1;
	add(u<<1,l,m,lazy[u]);add(u<<1|1,m,r,lazy[u]);lazy[u]=0;
	return ;
}

inline void modify(int u,int l,int r,int v,int pl,int pr)
{
	if (l==pl&&r==pr)
	{
		add(u,l,r,v);
		return ;
	}
	PushDown(u,pl,pr);int m=pl+pr>>1;
	if (r<=m) modify(u<<1,l,r,v,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,v,m,pr);
	else
	{
		modify(u<<1,l,m,v,pl,m);
		modify(u<<1|1,m,r,v,m,pr);
	}
	x[u]=x[u<<1]+x[u<<1|1];
	return ;
}

inline long long query(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return x[u];
	PushDown(u,pl,pr);int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else return query(u<<1,l,m,pl,m)+query(u<<1|1,m,r,m,pr);
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='M'){x=0;return ;}
		if (ch=='Q'){x=1;return ;}
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(n);read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	BuildTree(1,1,n+1);
	while (m--)
	{
		read(o);read(p);
		if (!o) read(v),modify(1,p,n+1,v-a[p],1,n+1),a[p]=v;
		else printf("%lld\n",query(1,1,p+1,1,n+1));
	}
	return 0;
}