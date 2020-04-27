#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,k,a[MAXN],c[MAXN],cnt[MAXN],ans,pt=1;
vector <int> v,res[MAXN];

int main()
{
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),++cnt[a[i]];
	sort(a+1,a+n+1,greater<int>());
	for (int i=k;i;i--) cnt[i]+=cnt[i+1];
	for (int i=1;i<=k;i++) scanf("%d",&c[i]);
	for (int i=k;i;i--)
		if (c[i]!=c[i-1])
		{
			v.push_back(i-1);
			ans=max(ans,(cnt[i]+c[i]-1)/c[i]);
		}
	int p=v.size()-1;
	printf("%d\n",ans);
	for (int i=1;i<=n;i++)
	{
		if (v[p]==a[i]) --p,pt=1;
		res[pt++].push_back(a[i]);
		if (pt>ans) pt-=ans;
	}
	for (int i=1;i<=ans;i++)
	{
		printf("%d",res[i].size());
		for (auto j:res[i]) printf(" %d",j);
		puts("");
	}
	return 0;
}