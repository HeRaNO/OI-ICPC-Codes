#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

const int M=73156157;

int x[1<<19][27],cnt[1<<19];
int n,T,l,r,o,a[MAXN],inv[MAXN];

inline void inc(int &x){++x;if (x==27) x=0;return ;}
inline void fadd(int &x,int y){x=y;if (x>=M) x-=M;return ;}
inline void finc(int &x,int y){x+=y;if (x>=27) x-=27;return ;}

void BuildTree(int u,int l,int r)
{
	if (l+1==r)
	{
		x[u][0]=a[l];int now=a[l];
		for (int i=1;i<27;i++)
		{
			int now2=1LL*now*now%M;
			now2=1LL*now2*now2%M;now=1LL*now2*now%M;
			x[u][i]=now;
		}
		return ;
	}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	for (int i=0;i<27;i++) fadd(x[u][i],x[u<<1][i]+x[u<<1|1][i]);
	return ;
}

void modify(int u,int l,int r,int pl,int pr)
{
	if (pl==l&&pr==r){inc(cnt[u]);return ;}
	int m=pl+pr>>1;
	if (r<=m) modify(u<<1,l,r,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,m,pr);
	else
	{
		modify(u<<1,l,m,pl,m);
		modify(u<<1|1,m,r,m,pr);
	}
	for (int i=0,p=cnt[u<<1],q=cnt[u<<1|1];i<27;inc(p),inc(q),++i)
		fadd(x[u][i],x[u<<1][p]+x[u<<1|1][q]);
	return ;
}

int query(int u,int l,int r,int c,int pl,int pr)
{
	finc(c,cnt[u]);if (pl==l&&pr==r) return x[u][c];
	int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,c,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,c,m,pr);
	int res;fadd(res,query(u<<1,l,m,c,pl,m)+query(u<<1|1,m,r,c,m,pr));
	return res;
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
	read(n);read(T);inv[1]=1;
	for (int i=2;i<=n;i++) inv[i]=1LL*(M-M/i)*inv[M%i]%M;
	for (int i=1;i<=n;i++) read(a[i]);
	BuildTree(1,1,n+1);
	while (T--)
	{
		read(o);read(l);read(r);
		if (o==1) modify(1,l,r+1,1,n+1);
		else printf("%d\n",1LL*query(1,l,r+1,0,1,n+1)*inv[r-l+1]%M);
	}
	return 0;
}