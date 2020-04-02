#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct LCIS
{
	int l,r,lans,rans,ans,len;
	LCIS(){}
	LCIS(int _l,int _r,int _ans,int _pl,int _pr,int _len):
		l(_l),r(_r),ans(_ans),lans(_pl),rans(_pr),len(_len){}
	LCIS operator + (const LCIS &a)const{
		LCIS res;res.l=l;res.r=a.r;res.ans=0;res.len=len+a.len;
		if (lans==len&&r<a.l) res.lans=lans+a.lans;
		else res.lans=lans;
		if (a.rans==a.len&&r<a.l) res.rans=a.rans+rans;
		else res.rans=a.rans;
		res.ans=max(res.lans,res.rans);
		int t;
		if (r<a.l) t=rans+a.lans;
		else t=0;
		res.ans=max(max(res.ans,ans),max(a.ans,t));
		return res;
	}
};

LCIS x[1<<18];
int T,n,m,o,l,r,v,lazy[1<<18],a[MAXN];

inline void BuildTree(int u,int l,int r)
{
	lazy[u]=0;
	if (l+1==r){x[u]=LCIS(a[l],a[l],1,1,1,1);return ;}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	x[u]=x[u<<1]+x[u<<1|1];return ;
}

inline void add(int u,int v)
{
	x[u].l+=v;x[u].r+=v;lazy[u]+=v;
	return ;
}

inline void PushDown(int u)
{
	if (!lazy[u]) return ;
	add(u<<1,lazy[u]);add(u<<1|1,lazy[u]);lazy[u]=0;
	return ;
}

inline void modify(int u,int l,int r,int v,int pl,int pr)
{
	if (l==pl&&r==pr){add(u,v);return ;}
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) modify(u<<1,l,r,v,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,v,m,pr);
	else
	{
		modify(u<<1,l,m,v,pl,m);
		modify(u<<1|1,m,r,v,m,pr);
	}
	x[u]=x[u<<1]+x[u<<1|1];return ;
}

inline LCIS query(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return x[u];
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else return query(u<<1,l,m,pl,m)+query(u<<1|1,m,r,m,pr);
}

inline void read(int &x)
{
	x=0;bool f=false;char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='a'){x=0;return ;}
		if (ch=='q'){x=1;return ;}
		if (ch=='-') f=true;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(T);
	for (int cas=1;cas<=T;cas++)
	{
		printf("Case #%d:\n",cas);
		read(n);read(m);
		for (int i=1;i<=n;i++) read(a[i]);
		BuildTree(1,1,n+1);
		while (m--)
		{
			read(o);read(l);read(r);
			if (!o) read(v),modify(1,l,r+1,v,1,n+1);
			else printf("%d\n",query(1,l,r+1,1,n+1).ans);
		}
	}
	return 0;
}