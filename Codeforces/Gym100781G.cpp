#include <bits/stdc++.h>
#define MAXN 100010
#define MAXW 10105
using namespace std;

int n,m,a,b,r,x[MAXN],y[MAXN];
int c[MAXW][MAXW];

inline int lowbit(int x){return x&-x;}

inline void modify(int i,int x,int v)
{
	for (++x;x<MAXW;x+=lowbit(x)) c[i][x]+=v;
	return ;
}

inline bool query(int i,int x)
{
	int res=0;
	for (++x;x;x-=lowbit(x)) res+=c[i][x];
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
	read(n);int ans=n;
	for (int i=1;i<=n;i++) read(x[i]),read(y[i]);
	read(m);
	for (int i=1;i<=m;i++)
	{
		read(a);read(b);read(r);
		for (int nx=max(a-r,0);nx<=a+r;nx++)
		{
			int d=abs(a-nx);
			double p=(double)b+sqrt(abs(r*r-d*d));
			double q=(double)b-sqrt(abs(r*r-d*d));
			int l=q,rr=p;l=max(l,0);
			if ((l-b)*(l-b)>r*r-d*d) ++l;
			if ((rr-b)*(rr-b)>r*r-d*d) --rr;
			modify(nx,l,1);modify(nx,rr+1,-1);
		}
	}
	for (int i=1;i<=n;i++) if (query(x[i],y[i])) --ans;
	printf("%d\n",ans);
	return 0;
}