#include <bits/stdc++.h>
#define MAXN 2000005
#define MAXB 1420
using namespace std;

const int INF=1e9;
int T,n,m,b,l,k,pt,a[MAXN],pos[MAXN],mx[MAXB];

inline void clean(int x)
{
	int l=(x-1)*b,r=x*b;
	for (int i=l;i<r&&i<n;i++) mx[x]=max(mx[x],a[i]);
	return ;
}

inline int getBlock(int x,int v)
{
	int l=(x-1)*b,r=x*b;
	for (int i=l;i<r;i++) if (a[i]>=v) return i;
	assert(false);
	return -1;
}

inline int query(int l,int r,int v)
{
	if (pos[l]==pos[r])
	{
		for (int i=l;i<=r;i++) if (a[i]>=v) return i;
		return -1;
	}
	for (int i=l,p=pos[l]*b;i<p;i++)
		if (a[i]>=v) return i;
	for (int i=pos[l]+1;i<pos[r];i++)
		if (mx[i]>=v) return getBlock(i,v);
	for (int i=(pos[r]-1)*b;i<=r;i++)
		if (a[i]>=v) return i;
	return -1;
}

inline void modify(int x)
{
	int l=(pos[x]-1)*b,r=pos[x]*b;a[x]=-INF;
	x=pos[x];mx[x]=-INF;
	for (int i=l;i<r&&i<n;i++) mx[x]=max(mx[x],a[i]);
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
	read(n);b=sqrt(n);m=n/b;
	if (n%b) ++m;
	for (int i=0;i<n;i++)
	{
		read(a[i]);
		pos[i]=i/b+1;
	}
	for (int i=1;i<=m;i++) clean(i);
	read(T);
	for (int i=0;i<T;i++)
	{
		read(l);read(k);k-=i;
		pt=query(l,n-1,k);
		if (!~pt&&l) pt=query(0,l-1,k);
		if (!~pt) puts("-1");
		else
		{
			l=pt-l+n;if (l>=n) l-=n;
			printf("%d\n",l);
			modify(pt);
		}
	}
	return 0;
}