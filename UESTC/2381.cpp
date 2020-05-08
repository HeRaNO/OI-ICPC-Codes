#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

const int INF=1e9;

int x[1<<21];
int T,n,m,l,r,k,pt,a[MAXN];

inline void BuildTree(int u,int l,int r)
{
	if (l+1==r){x[u]=a[l];return ;}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	x[u]=max(x[u<<1],x[u<<1|1]);
	return ;
}

inline void modify(int u,int p,int v,int pl,int pr)
{
	if (pl+1==pr){x[u]+=v;return ;}
	int m=pl+pr>>1;
	if (p<m) modify(u<<1,p,v,pl,m);
	else modify(u<<1|1,p,v,m,pr);
	x[u]=max(x[u<<1],x[u<<1|1]);
	return ;
}

inline int query(int u,int l,int r,int v,int pl,int pr)
{
	if (pl+1==pr) return x[u]>=v?l:-1;
	if (x[u]<v) return -1;
	int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,v,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,v,m,pr);
	else
	{
		int t=query(u<<1,l,m,v,pl,m);
		if (~t) return t;
		return query(u<<1|1,m,r,v,m,pr);
	}
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
	read(T);
	while (T--)
	{
		read(n);read(m);
		for (int i=1;i<=n;i++) read(a[i]);
		BuildTree(1,1,n+1);
		while (m--)
		{
			read(l);read(r);read(k);
			printf("%d\n",pt=query(1,l,r+1,k,1,n+1));
			if (pt!=-1) modify(1,pt,-k,1,n+1);
		}
	}
	return 0;
}