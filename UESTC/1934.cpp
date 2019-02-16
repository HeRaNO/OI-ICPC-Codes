#include <cstdio>
#define MAXN 50010
using namespace std;

int n,T,o,l,r,x,a[MAXN],c[MAXN];

inline int lowbit(int x){return x&-x;}
inline void modify(int x,long long v){for(;x<=n;x+=lowbit(x)) c[x]+=v;return ;}
inline long long query(int x){long long r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(n);T=n;
	for (int i=1;i<=n;i++) read(a[i]);
	while (T--)
	{
		read(o);read(l);read(r);read(x);
		if (!o) modify(l,x),modify(r+1,-x);
		else printf("%lld\n",query(r)+a[r]);
	}
	return 0;
}