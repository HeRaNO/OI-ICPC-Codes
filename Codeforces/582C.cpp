#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,a[MAXN],b[MAXN<<1],c[MAXN],g[MAXN],mx[MAXN];
long long ans;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++) g[i]=__gcd(i,n);
	for (int i=1;i<n;i++)
		if (!(n%i))
		{
			memset(mx,0,i<<2);
			for (int j=1;j<=n;j++) c[j]=c[j-1]+(g[j]==i);
			for (int j=0;j<n;j++) mx[j%i]=max(mx[j%i],a[j]);
			for (int j=0;j<n;j++) b[j]=b[j+n]=(mx[j%i]==a[j]);
			for (int j=(n-1)<<1;~j;j--) if (b[j]) b[j]+=b[j+1];
			for (int j=0;j<n;j++) ans+=c[min(n-1,b[j])];
		}
	printf("%lld\n",ans);
	return 0;
}
