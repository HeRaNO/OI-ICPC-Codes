#include <bits/stdc++.h>
#define fi first
#define se second
#define MAXN 1010
#define MAXM 500010
using namespace std;

int n,m,k,f[MAXN],p,ans;
pair <int,pair<int,int> > e[MAXM];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(n);read(m);read(k);p=n;
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++) read(e[i].se.fi),read(e[i].se.se),read(e[i].fi);
	sort(e+1,e+m+1);
	for (int i=1;i<=m;i++)
	{
		int fx=getf(e[i].se.fi),fy=getf(e[i].se.se);
		if (fx!=fy)
		{
			f[fy]=fx;--p;ans+=e[i].fi;
			if (p==k) return printf("%d\n",ans),0;
		}
	}
	return 0;
}