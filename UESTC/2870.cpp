#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

struct Point
{
	long long x,y;
	Point():x(0),y(0){}
	Point(long long _x,long long _y):x(_x),y(_y){}
	Point operator + (const Point &a)const{
		return Point(x+a.x,y+a.y);
	}
	Point operator - (const Point &a)const{
		return Point(x-a.x,y-a.y);
	}
	Point operator * (const long long &a)const{
		return Point(x*a,y*a);
	}
};

const Point d[]={
	Point(1,0),Point(-1,0),Point(0,1),Point(0,-1)
};

int n,m,mp[128];
char s[MAXN];
int x[1<<19][4];
long long t[1<<19][4],lazy[1<<19][4];

void BuildTree(int u,int l,int r)
{
	if (l+1==r){++x[u][mp[s[l]]];++t[u][mp[s[l]]];return ;}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	for (int i=0;i<4;i++)
	{
		x[u][i]=x[u<<1][i]+x[u<<1|1][i];
		t[u][i]=t[u<<1][i]+t[u<<1|1][i];
	}
	return ;
}

void add(int u,int p,int v)
{
	t[u][p]+=1LL*v*x[u][p];
	lazy[u][p]+=v;
	return ;
}

void PushDown(int u)
{
	for (int i=0;i<4;i++)
		if (lazy[u][i])
		{
			add(u<<1,i,lazy[u][i]);
			add(u<<1|1,i,lazy[u][i]);
			lazy[u][i]=0;
		}
	return ;
}

void modify(int u,int l,int r,int x,int pl,int pr)
{
	if (l==pl&&r==pr){add(u,x,1);return ;}
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) modify(u<<1,l,r,x,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,x,m,pr);
	else
	{
		modify(u<<1,l,m,x,pl,m);
		modify(u<<1|1,m,r,x,m,pr);
	}
	for (int i=0;i<4;i++)
		t[u][i]=t[u<<1][i]+t[u<<1|1][i];
	return ;
}

Point query(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr)
	{
		Point r;
		for (int i=0;i<4;i++) r=r+d[i]*t[u][i];
		return r;
	}
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else return query(u<<1,l,m,pl,m)+query(u<<1|1,m,r,m,pr);
}

int main()
{
	mp['E']=0;mp['W']=1;mp['N']=2;mp['S']=3;
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	BuildTree(1,1,n+1);
	while (m--)
	{
		int o;scanf("%d",&o);
		if (o==1)
		{
			int l,r;char x[3];
			scanf("%d %d %s",&l,&r,x);
			modify(1,l,r+1,mp[x[0]],1,n+1);
		}
		else
		{
			int l,r,T;
			scanf("%d %d %d",&l,&r,&T);
			int t=T/(r-l+1),q=T%(r-l+1);
			Point v,vt,vq;
			if (t) vt=query(1,l,r+1,1,n+1);
			if (q) vq=query(1,l,l+q,1,n+1);
			v=vt*t+vq;
			printf("%lld %lld\n",v.x,v.y);
		}
	}
	return 0;
}