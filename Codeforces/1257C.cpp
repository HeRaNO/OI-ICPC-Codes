#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
 
int T,n,a[MAXN];
vector <int> v[MAXN];
 
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) v[i].clear();
		for (int i=1,x;i<=n;i++)
		{
			scanf("%d",&x);
			v[x].push_back(i);
		}
		int ans=~(1<<31);
		for (int i=1;i<=n;i++)
		{
			int sz=(int)v[i].size()-1;
			for (int j=0;j<sz;j++) ans=min(ans,v[i][j+1]-v[i][j]+1);
		}
		if (ans==~(1<<31)) puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}