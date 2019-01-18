#include <cstdio>
#include <algorithm>
#define MAXN 100010
#define mp make_pair
#define fi first
#define se second
using namespace std;

pair<int,pair<int,int> > a[MAXN];
int n,m,x,y,c,f[MAXN],fx,fy,s,ans,cnt;

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(n);read(m);
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++)
	{
		read(x);read(y);read(c);s+=c;
		a[i]=mp(c,mp(x,y));
	}
	sort(a+1,a+m+1);
	for (int i=m;i;i--)
	{
		fx=getf(a[i].se.fi);fy=getf(a[i].se.se);
		if (fx!=fy)
		{
			f[fy]=fx;ans+=a[i].fi;++cnt;
		}
		if (cnt==n-1)
		{
			printf("%d\n",s-ans);
			return 0;
		}
	}
	puts("0");
	return 0;
}