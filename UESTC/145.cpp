#include <cstdio>
#include <algorithm>
#define mp make_pair
#define fi first
#define se second
#define MAXM 1000010
#define MAXN 1010
using namespace std;

pair<int,pair<int,int> > e[MAXM];
int n,m,T,ans,a,b,c,f[MAXN],fx,fy;

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(T);
	while (T--)
	{
		read(n);read(m);
		for (int i=1;i<=n;i++) f[i]=i;
		for (int i=1;i<=m;i++)
		{
			read(a);read(b);read(c);
			e[i]=mp(c,mp(a,b));
		}
		sort(e+1,e+m+1);int ans=0,cnt=0;
		for (int i=1;i<=m;i++)
		{
			fx=getf(e[i].se.fi);fy=getf(e[i].se.se);
			if (f[fx]!=fy)
			{
				f[fx]=fy;
				ans+=e[i].fi;
				++cnt;
				if (cnt==n-1)
				{
					printf("%d\n",ans);
					break;
				}
			}
		}
	}
	return 0;
}