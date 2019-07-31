#include <bits/stdc++.h>
#define MAXN 400010
using namespace std;

int n,I,k,m,cnt[MAXN],a[MAXN],ans=~(1<<31);
pair <int,int*> b[MAXN];

int main()
{
	scanf("%d %d",&n,&I);k=(I<<3)/n;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=make_pair(a[i],&a[i]);
	if (k>=19) return puts("0"),0;
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++)
	{
		if (b[i].first!=b[i-1].first) ++m;
		*b[i].second=m;
	}
	for (int i=1;i<=n;i++) ++cnt[a[i]];
	for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
	for (int i=1<<k,p=0;i<=m;i++,p++) ans=min(ans,cnt[m]-(cnt[i]-cnt[p]));
	printf("%d\n",ans==~(1<<31)?0:ans);
	return 0;
}