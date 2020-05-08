#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1005
using namespace std;

struct Q
{
	int x,y,l,d;
	Q(){}
	Q(int _x,int _y,int _l,int _d):x(_x),y(_y),l(_l),d(_d){}
};

Q a[MAXN];
int n,T,R,cnt,u,v,w,z,o;
long long c[MAXN][MAXN],lazy[MAXN][MAXN];

inline void Rebuild()
{
	memset(lazy,0,sizeof lazy);
	for (;cnt;cnt--)
		for (int i=a[cnt].y,j=a[cnt].x;i<a[cnt].y+a[cnt].l;i++,j++)
			lazy[i][j]+=a[cnt].d,lazy[i][a[cnt].x+a[cnt].l]-=a[cnt].d;
	for (int i=1;i<=n;i++)
	{
		long long t=0,tt=0;
		for (int j=i;j<=n;j++)
		{
			t+=lazy[i][j];tt+=t;
			c[i][j]+=tt;
		}
	}
	return ;
}

inline long long query(int x,int y,int r)
{
	long long res=0LL;
	for (int i=y,j=x-1;i<y+r;i++,j++) res+=c[i][x+r-1]-c[i][j];
	for (int i=1;i<=cnt;i++)
	{
		int xx=min(x+r-1,a[i].x+a[i].l-1);
		int yy=max(y,a[i].y);
		int rr=max(x-y,a[i].x-a[i].y);
		if (x>xx||a[i].x>xx) continue;
		if (y+r-1<yy||a[i].y+a[i].l-1<yy) continue;
		if (x+r-1-y<rr||a[i].x+a[i].l-1-a[i].y<rr) continue;
		long long len=xx-yy-rr+1;
		res+=len*(len+1)/2*a[i].d;
	}
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
	read(n);read(T);R=n;
	while (T--)
	{
		read(o);read(u);read(v);read(w);
		if (o==1)
		{
			read(z);a[++cnt]=Q(u,v,w,z);
			if (cnt==R) Rebuild();
		}
		else printf("%lld\n",query(u,v,w));
	}
	return 0;
}
