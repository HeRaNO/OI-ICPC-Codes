#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,T,ans;
pair <int,int> a[MAXN];
set <int> s;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);s.clear();ans=0;
		for (int i=1;i<=n;i++)
			scanf("%d %d",&a[i].second,&a[i].first);
		sort(a+1,a+n+1);
		for (int i=1;i<=n;i++)
			for (int j=a[i].second;j<=a[i].first;j++)
				if (!s.count(j))
				{
					s.insert(j);
					++ans;break;
				}
		printf("%d\n",ans);
	}
	return 0;
}