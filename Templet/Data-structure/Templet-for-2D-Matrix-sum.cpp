#include <bits/stdc++.h>
#define MAXW 1<<12|1
#define MAXQ 1200005
using namespace std;

struct Mokia
{
	int x,y,o,d,p,pt;
	Mokia(){}
	Mokia(int _x,int _y,int _o,int _d,int _p,int _pt):
		x(_x),y(_y),o(_o),d(_d),p(_p),pt(_pt){}
	bool operator < (const Mokia &a)const{
		if (x==a.x&&y==a.y) return o<a.o;
		return x==a.x?y<a.y:x<a.x;
	}
};

Mokia q[MAXQ],t[MAXQ];
int n,m,T,o,x,y,u,v,k,Q;
long long c[MAXW],ans[MAXQ];

inline long long f(int x,long long v){return x>0?v:-v;}
inline int lowbit(int x){return x&-x;}
inline void modify(int x,long long v){for (;x<=m;x+=lowbit(x)) c[x]+=v;return ;}
inline long long query(int x){long long r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}

void CDQ(int l,int r)
{
	if (l==r) return ;
	int mid=l+r>>1,ll=l,rl=mid+1;
	for (int i=l;i<=r;i++)
	{
		if (q[i].p<=mid&&!q[i].o) modify(q[i].y,q[i].d);
		else if (q[i].p>mid&&q[i].o) ans[q[i].pt]+=f(q[i].d,query(q[i].y));
	}
	for (int i=l;i<=r;i++)
		if (q[i].p<=mid&&!q[i].o) modify(q[i].y,-q[i].d);
	for (int i=l;i<=r;i++)
		if (q[i].p<=mid) t[ll++]=q[i];
		else t[rl++]=q[i];
	for (int i=l;i<=r;i++) q[i]=t[i];
	CDQ(l,mid);CDQ(mid+1,r);
	return ;
}

inline void addQuery(int x,int y)
{
	++Q;++T;q[T]=Mokia(x,y,1,1,T,Q);
	return ;
}

inline void addModify(int x,int y,int u,int v,int k)
{
	++u;++v;
	++T;q[T]=Mokia(u,v,0,k,T,0);
	++T;q[T]=Mokia(x,v,0,-k,T,0);
	++T;q[T]=Mokia(u,y,0,-k,T,0);
	++T;q[T]=Mokia(x,y,0,k,T,0);
	return ;
}

inline void addModify(int x,int y,int k)
{
	++T;q[T]=Mokia(x,y,0,k,T,0);
	return ;
}

inline void addQuery(int x,int y,int u,int v)
{
	++Q;
	++T;q[T]=Mokia(u,v,1,1,T,Q);
	++T;q[T]=Mokia(x-1,v,1,-1,T,Q);
	++T;q[T]=Mokia(u,y-1,1,-1,T,Q);
	++T;q[T]=Mokia(x-1,y-1,1,1,T,Q);
	return ;
}
