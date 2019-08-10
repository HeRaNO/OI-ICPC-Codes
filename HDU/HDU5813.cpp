#include <bits/stdc++.h>
typedef long long ll;
const int MAXN=1505;
using namespace std;
pair<int,int> p[MAXN];

int main()
{
	int T,kase;
	scanf("%d",&T);
	kase=T;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&p[i].first);
			p[i].second=i;
		}
		sort(p+1,p+n+1);
		printf("Case #%d: ",kase-T);
		int temp=0,ans=0;
		bool flag=false;
		for(int i=1;i<=n;i++)
		{
			ans+=p[i].first;
			if(p[i].first!=p[i-1].first)
				temp=i-1;
			if(p[i].first>temp)
			{
				printf("No\n");
				flag=true;
				break;
			}
		}
		if(flag)continue;
		printf("Yes\n%d\n",ans);
		for(int i=n;i>=2;i--)
		{
			for(int j=1;j<=p[i].first;j++)
			{
				printf("%d %d\n",p[i].second,p[j].second);
			}
		}
	}
	return 0;
}