#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,m,a[MAXN],b[MAXN];
long long ans;
pair <int,int> p[MAXN];

void DC(int l,int r)
{
	if (l>=r) return ;
	int m=l+r>>1;int i=l,j=m+1,k=l;
	DC(l,m);DC(m+1,r);
	while (i<=m&&j<=r)
	{
		if (a[i]<=a[j]) b[k++]=a[i++];
		else{ans+=(j-k);b[k++]=a[j++];}
	}
	while (i<=m) b[k++]=a[i++];
	while (j<=r) b[k++]=a[j++];
	for (int i=l;i<=r;i++) a[i]=b[i];
	return ;
}

int main()
{
	scanf("%d %d",&n,&m);
	scanf("%d %d",&n,&m);
	ans=1LL*(n+1)*(m+1);
	for (int i=1;i<=n;i++)
		scanf("%d %d",&p[i].first,&p[i].second);
	sort(p+1,p+n+1);
	for (int i=1;i<=n;i++) a[i]=p[i].second;
	DC(1,n);
	for (int i=1;i<=m;i++)
		scanf("%d %d",&p[i].first,&p[i].second);
	sort(p+1,p+m+1);
	for (int i=1;i<=m;i++) a[i]=p[i].second;
	DC(1,m);
	printf("%lld\n",ans);
	return 0;
}