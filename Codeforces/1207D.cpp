#include <bits/stdc++.h>
#define MAXN 300005
using namespace std;

const long long M=998244353LL;

int n,m,x,y,a[MAXN],b[MAXN],cnt[MAXN];
long long fac[MAXN],p=1,q=1,r=1;
pair <int,int> c[MAXN];

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(n);fac[0]=1LL;
	for (int i=1;i<=n;i++)
	{
		fac[i]=fac[i-1]*i%M;
		read(x);read(y);
		++a[x];++b[y];c[i]=make_pair(x,y);
	}
	for (int i=1;i<=n;i++)
	{
		(p*=fac[a[i]])%=M;
		(q*=fac[b[i]])%=M;
	}
	sort(c+1,c+n+1);
	for (int i=1;i<=n;i++)
	{
		if (c[i]!=c[i-1]) ++m;
		++cnt[m];
		if (c[i].second<c[i-1].second)
		{
			r=0;break;
		}
	}
	for (int i=1;i<=m&&r;i++) (r*=fac[cnt[i]])%=M;
	long long ans=fac[n];
	ans=(ans-p+M)%M;ans=(ans-q+M)%M;(ans+=r)%=M;
	printf("%lld\n",ans);
	return 0;
}