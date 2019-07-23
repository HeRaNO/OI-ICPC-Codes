#include <bits/stdc++.h>
#define MAXN 300010
using namespace std;

int n,k;
long long ans,a[MAXN];
priority_queue <long long,vector<long long>,greater<long long> > q;

int main()
{
	scanf("%d %d",&n,&k);k--;
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<n;i++) q.push(a[i]-a[i+1]);
	while (k>0) ans+=q.top(),q.pop(),k--;
	printf("%lld\n",ans+a[n]-a[1]);
	return 0;
}