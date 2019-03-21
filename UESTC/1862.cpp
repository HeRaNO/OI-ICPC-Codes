#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200010
#define MXLOG 61
using namespace std;

int n,T,r;
long long a[MAXN],p[MXLOG];

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

inline void read(long long &x)
{
	x=0LL;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3LL)+(x<<1LL)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(T);
	while (T--)
	{
		read(n);memset(p,0,sizeof p);r=0;
		for (int i=0;i<n;i++) read(a[i]);
		sort(a,a+n);n=unique(a,a+n)-a;
		for (int i=0;i<n;i++)
			for (int j=60;~j;j--)
			{
				if (!(a[i]>>j)) continue;
				if (!p[j]){p[j]=a[i];break;}
				a[i]^=p[j];
			}
		for (int i=0;i<=60;i++) if (p[i]) ++r;
		printf("%lld\n",(1LL<<r)-n);
	}
	return 0;
}