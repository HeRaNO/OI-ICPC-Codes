#include <bits/stdc++.h>
#define MAXN 300005
using namespace std;

int x[1<<19],hh,gg,q,ori[MAXN];
int u[MAXN],d[MAXN],l[MAXN],r[MAXN],c[MAXN],p[MAXN],tr[MAXN],tu[MAXN],n,ans,cnt,mny,mxy;
pair <int,int> a[MAXN];
pair <int,int*> h[MAXN],g[MAXN];

inline int lowbit(int x){return x&-x;}
inline void modify(int x,int v){for (;x<=gg;x+=lowbit(x)) c[x]+=v;return ;}
inline int query(int x){int r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}
inline int query(int l,int r){if (l>r) return 0;return query(r)-query(l-1);}

inline void modify(int u,int x,int v,int p,int r)
{
	if (p+1==r){::x[u]=v;return ;}
	int m=p+r>>1;
	if (x<m) modify(u<<1,x,v,p,m);
	else modify(u<<1|1,x,v,m,r);
	::x[u]=max(::x[u<<1],::x[u<<1|1]);
	return ;
}

inline int query(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return x[u];
	int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else return max(query(u<<1,l,m,pl,m),query(u<<1|1,m,r,m,pr));
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
	read(n);read(q);
	for (int i=1;i<=n;i++)
	{
		read(a[i].first),read(a[i].second);
		h[i]={a[i].first,&a[i].first};
		g[i]={a[i].second,&a[i].second};
	}
	sort(h+1,h+n+1);sort(g+1,g+n+1);h[0].first=g[0].first=-1;
	for (int i=1;i<=n;i++)
	{
		if (h[i-1].first!=h[i].first) ++hh;
		*h[i].second=hh;
		if (g[i-1].first!=g[i].first) ++gg;
		*g[i].second=gg;ori[gg]=g[i].first;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		++u[a[i].first];++tu[a[i].first];
		++r[a[i].second];++tr[a[i].second];
	}
	for (int i=1;i<=n;i++)
	{
		--r[a[i].second];--u[a[i].first];
		++l[a[i].second];++d[a[i].first];
		modify(1,a[i].second,min(l[a[i].second],r[a[i].second]),1,gg+1);
		if (i>1&&a[i].first==a[i-1].first&&ori[a[i].second]>ori[a[i-1].second]+1)
		{
			int now=min(u[a[i].first]+1,d[a[i].first]-1);
			now=min(now,query(1,a[i-1].second,a[i].second+1,1,gg+1));
			ans=max(ans,now);
		}
	}
	if (q==1) return printf("%d\n",ans),0;
	memset(l,0,sizeof l);memset(d,0,sizeof l);
	for (int i=1;i<=n;i++)
	{
		--tr[a[i].second];--tu[a[i].first];
		++l[a[i].second];++d[a[i].first];
		int x=(min(l[a[i].second],tr[a[i].second])>=ans);
		modify(a[i].second,x-p[a[i].second]);
		p[a[i].second]=x;
		if (i>1&&a[i].first==a[i-1].first&&ori[a[i].second]>ori[a[i-1].second]+1&&min(tu[a[i].first]+1,d[a[i].first]-1)>=ans)
			cnt+=query(a[i-1].second+1,a[i].second-1);
	}
	printf("%d\n",cnt);
	return 0;
}