#include <bits/stdc++.h>
#define MAXN 100005
#define MAXB 320
using namespace std;

int n,m,T,l,r,v,pos[MAXN],a[MAXN],c[MAXB];
bool f[MAXB];

inline void clean(int x)
{
	if (!f[x]) return ;
	for (int l=(x-1)*m+1,r=x*m;l<=r&&l<=n;l++) a[l]=c[x];
	f[x]=false;
	return ;
}

inline int modify(int l,int r,int v)
{
	int res=0;
	if (pos[l]==pos[r])
	{
		clean(pos[l]);
		for (int i=l;i<=r;i++) a[i]==v?++res:a[i]=v;
		return res;
	}
	clean(pos[l]);clean(pos[r]);
	for (int i=l,p=pos[l]*m;i<=p;i++) a[i]==v?++res:a[i]=v;
	for (int i=pos[l]+1;i<pos[r];i++)
	{
		if (f[i]) c[i]==v?res+=m:c[i]=v;
		else
		{
			for (int j=(i-1)*m+1,p=i*m;j<=p;j++)
				a[j]==v?++res:a[j]=v;
			f[i]=true;c[i]=v;
		}
	}
	for (int i=(pos[r]-1)*m+1;i<=r;i++) a[i]==v?++res:a[i]=v;
	return res;
}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(n);m=(int)sqrt(n);
	for (int i=1;i<=n;i++) read(a[i]),pos[i]=(i-1)/m+1;
	read(T);
	while (T--)
	{
		read(l);read(r);read(v);
		printf("%d\n",r-l+1-modify(l,r,v));
	}
	return 0;
}