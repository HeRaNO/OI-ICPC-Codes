#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,m,a[MAXN],b[MAXN],c[MAXN],d[MAXN],r[MAXN];
int x[1<<18];

inline void BuildTree(int u,int l,int r)
{
	if (l+1==r){x[u]=1;return ;}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	x[u]=x[u<<1]+x[u<<1|1];
	return ;
}

inline void modify(int u,int p,int l,int r)
{
	if (l+1==r){x[u]=0;return ;}
	int m=l+r>>1;
	p<m?modify(u<<1,p,l,m):modify(u<<1|1,p,m,r);
	x[u]=x[u<<1]+x[u<<1|1];
	return ;
}

inline int query(int k)
{
	int u=1,l=1,r=n+1;
	while (l+1!=r)
	{
		int m=l+r>>1;u<<=1;
		if (k<=x[u]) r=m;
		else l=m,k-=x[u++];
	}
	return l;
}

inline int query(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return x[u];
	int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else return query(u<<1,l,m,pl,m)+query(u<<1|1,m,r,m,pr);
}

inline void mul(int a[],int b[])
{
	for (int i=1;i<=n;i++) c[i]=b[a[i]];
	for (int i=1;i<=n;i++) a[i]=c[i];
	return ;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) a[i]=i;
	while (m--)
	{
		int k,x;
		scanf("%d %d",&k,&x);
		for (int i=1;i<=n;i++) r[i]=i;
		BuildTree(1,1,n+1);
		for (int i=0,p=1;i<n;i++)
		{
			b[i+1]=query((p+k-2)%(n-i)+1);
			p=query(1,1,b[i+1]+1,1,n+1);modify(1,b[i+1],1,n+1);
		}
		for (;x;x>>=1,mul(b,b)) if (x&1) mul(r,b);
		for (int i=1;i<=n;i++) d[r[i]]=i;
		for (int i=1;i<=n;i++) c[d[i]]=a[i];
		for (int i=1;i<=n;i++) a[i]=c[i];
	}
	for (int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	return 0;
}