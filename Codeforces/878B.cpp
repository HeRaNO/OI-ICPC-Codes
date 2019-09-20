#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,m,k,x,l,r,top;
long long ans;
pair <int,int> a[MAXN];

int main()
{
	scanf("%d %d %d",&n,&k,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (top&&a[top].first==x)
		{
			++a[top].second;
			if (a[top].second==k) --top;
		}
		else a[++top]=make_pair(x,1);
	}
	if (!top) return puts("0"),0;
	for (int i=1;i<=top;i++) ans+=a[i].second;
	if (m==1) return printf("%lld\n",ans),0;
	ans*=m;l=1;r=top;
	while (l<r)
	{
		if (a[l].first!=a[r].first) return printf("%lld\n",ans),0;
		if (a[l].second+a[r].second!=k)
		{
			if (a[l].second+a[r].second>k) ans-=1LL*(m-1)*k;
			return printf("%lld\n",ans),0;
		}
		ans-=1LL*(m-1)*k;
		++l;--r;
	}
	if (l>r) return puts("0"),0;
	long long x=1LL*a[l].second*m;
	if (x%k) printf("%lld\n",ans-x/k*k);
	else puts("0");
	return 0;
}