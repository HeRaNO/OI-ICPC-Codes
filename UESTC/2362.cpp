#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,k,x;
long long ans,all,a[MAXN],b[MAXN],g;

void DC(int l,int r)
{
	if (l>=r) return ;
	int m=l+r>>1;int i=l,j=m+1,k=l;
	DC(l,m);DC(m+1,r);
	while (i<=m&&j<=r)
	{
		if (a[i]<a[j]) b[k++]=a[i++];
		else{ans+=(j-k);b[k++]=a[j++];}
	}
	while (i<=m) b[k++]=a[i++];
	while (j<=r) b[k++]=a[j++];
	for (int i=l;i<=r;i++) a[i]=b[i];
	return ;
}

int main()
{
	scanf("%d %d",&n,&k);all=1LL*n*(n+1);all>>=1;
	for (int i=1;i<=n;i++) scanf("%d",&x),a[i]=a[i-1]+x-k;
	DC(0,n);g=__gcd(ans,all);
	printf("%lld/%lld\n",ans/g,all/g);
	return 0;
}
