#include <bits/stdc++.h>
#define MAXN 251
using namespace std;

int cnt[200000],n,k,ans,x;

int main()
{
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		++cnt[x];
		--cnt[x+1000];
	}
	for (int i=1;i<=101000;i++) cnt[i]+=cnt[i-1];
	for (int i=1;i<=101000;i++) ans=max(ans,cnt[i]);
	printf("%d\n",ans/k+(ans%k!=0));
	return 0;
}