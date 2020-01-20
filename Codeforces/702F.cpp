#include <bits/stdc++.h>
#define MAXN 200005
#define lson(x) son[(x)][0]
#define rson(x) son[(x)][1]
using namespace std;

struct TShirt
{
	int c,q;
	bool operator < (const TShirt &a)const{
		return q==a.q?c<a.c:q>a.q;
	}
};

TShirt a[MAXN];
int n,m,rt,val[MAXN],ans[MAXN],rnd[MAXN];
int lazy[MAXN][2],son[MAXN][2];

inline int Rand(){int r=rand();return r<<15|rand();}

inline void PushDown(int u)
{
	if (lazy[u][0])
	{
		val[lson(u)]+=lazy[u][0];lazy[lson(u)][0]+=lazy[u][0];
		val[rson(u)]+=lazy[u][0];lazy[rson(u)][0]+=lazy[u][0];
		lazy[u][0]=0;
	}
	if (lazy[u][1])
	{
		ans[lson(u)]+=lazy[u][1];lazy[lson(u)][1]+=lazy[u][1];
		ans[rson(u)]+=lazy[u][1];lazy[rson(u)][1]+=lazy[u][1];
		lazy[u][1]=0;
	}
	return ;
}

inline void spilt(int u,int &x,int &y,int k)
{
	if (!u){x=y=0;return ;}
	PushDown(u);
	if (val[u]<k){x=u;spilt(rson(u),rson(x),y,k);}
	else {y=u;spilt(lson(u),x,lson(y),k);}
	return ;
}

inline int merge(int x,int y)
{
	if (!x||!y) return x+y;
	if (rnd[x]<rnd[y])
	{
		PushDown(x);
		rson(x)=merge(rson(x),y);
		return x;
	}
	else
	{
		PushDown(y);
		lson(y)=merge(x,lson(y));
		return y;
	}
}

inline int add(int x,int y)
{
	int a=0,b=0;spilt(x,a,b,val[y]);
	return merge(merge(a,y),b);
}

inline int Build(int x,int y)
{
	if (!x) return y;
	PushDown(x);
	y=Build(lson(x),y);y=Build(rson(x),y);
	lson(x)=rson(x)=0;
	return add(y,x);
}

inline void down(int x)
{
	if (!x) return ;
	PushDown(x);down(lson(x));down(rson(x));
	return ;
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
	srand((unsigned int)time(NULL));
	read(n);
	for (int i=1;i<=n;i++) read(a[i].c),read(a[i].q);
	sort(a+1,a+n+1);
	read(m);
	for (int i=1;i<=m;i++)
	{
		read(val[i]);rnd[i]=Rand();rt=add(rt,i);
	}
	for (int i=1;i<=n;i++)
	{
		int x=0,y=0;spilt(rt,x,y,a[i].c);
		val[y]-=a[i].c;++ans[y];
		lazy[y][0]-=a[i].c;++lazy[y][1];
		int p=0,q=0;
		spilt(y,p,q,a[i].c-1);x=Build(p,x);
		rt=merge(x,q);
	}
	down(rt);
	for (int i=1;i<=m;i++) printf("%d%c",ans[i],i==m?'\n':' ');
	return 0;
}