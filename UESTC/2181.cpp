#include <bits/stdc++.h>
#define MAXN 5005
using namespace std;

struct I
{
	long long v,w,h;
	bool operator <(const I &a)const{
		return h<a.h;
	}
}a[MAXN];

int n,m;
long long dp[MAXN],ans,k,x,y,b,c,d,h;

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

inline void read(long long &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(n);read(m);read(k);read(x);read(y);
	for (int i=1;i<=n;i++)
	{
		read(a[i].v);read(b);read(c);read(d);
		a[i].w=max((c-b)*y,0LL);a[i].h=max((d-k)*x,0LL);
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		for (int j=m-a[i].h;j>=a[i].w;j--)
			dp[j]=max(dp[j],dp[j-a[i].w]+a[i].v);
	for (int i=m;~i;i--) ans=max(ans,dp[i]);
	printf("%lld\n",ans);
	return 0;
}
