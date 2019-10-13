#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,m,x,a[MAXN],b[MAXN],ans=2;
map <int,int> mp;

int main()
{
	scanf("%d %d",&n,&x);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d %d",&m,&x);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	for (int i=1;i<1e9;i<<=1)
	{
		int p=i<<1;
		mp.clear();
		for (int j=1;j<=n;j++) ++mp[a[j]&(p-1)];
		for (int j=1;j<=m;j++) ++mp[(b[j]+i)&(p-1)];
		for (auto it:mp) ans=max(ans,it.second);
	}
	printf("%d\n",ans);
	return 0;
}