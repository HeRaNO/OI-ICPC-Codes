#include <bits/stdc++.h>
#define MAXN 500005
using namespace std;

int n,q,cnt,o,l,r,x,a[MAXN];
int t[1<<20];

inline int gcd(int a,int b){return !b?a:gcd(b,a%b);}

void BuildTree(int u,int l,int r)
{
	if (l+1==r){t[u]=a[l];return ;}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	t[u]=gcd(t[u<<1],t[u<<1|1]);
	return ;
}

inline void modify(int u,int x,int v,int pl,int pr)
{
	if (pl+1==pr){t[u]=v;return ;}
	int m=pl+pr>>1;
	if (x<m) modify(u<<1,x,v,pl,m);
	else modify(u<<1|1,x,v,m,pr);
	t[u]=gcd(t[u<<1],t[u<<1|1]);
	return ;
}

inline void query(int u,int l,int r,int x,int pl,int pr)
{
	if (cnt>1) return ;
	if (pl+1==pr){++cnt;return ;}
	int m=pl+pr>>1;
	if (r<=m)
	{
		if (t[u<<1]%x) query(u<<1,l,r,x,pl,m);
		return ;
	}
	else if (m<=l)
	{
		if (t[u<<1|1]%x) query(u<<1|1,l,r,x,m,pr);
		return ;
	}
	else
	{
		if (t[u<<1]%x) query(u<<1,l,m,x,pl,m);
		if (cnt>1) return ;
		if (t[u<<1|1]%x) query(u<<1|1,m,r,x,m,pr);
	}
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
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	BuildTree(1,1,n+1);
	read(q);
	while (q--)
	{
		read(o);
		if (o==1)
		{
			read(l);read(r);read(x);cnt=0;
			query(1,l,r+1,x,1,n+1);
			if (cnt>1) puts("NO");
			else puts("YES");
		}
		else
		{
			read(l);read(x);
			modify(1,l,x,1,n+1);
		}
	}
	return 0;
}