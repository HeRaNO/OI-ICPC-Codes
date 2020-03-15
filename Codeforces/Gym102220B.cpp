#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,m,a[MAXN];
vector <int> v[MAXN],ans[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);
		for (int i=1;i<=m;i++) scanf("%d",&a[i]);
		for (int i=1,x,y;i<=n;i++)
		{
			scanf("%d %d",&x,&y);
			v[y].push_back(x);
		}
		for (int i=1;i<=m;i++)
		{
			sort(v[i].begin(),v[i].end(),greater<int>());
			int now=0;
			for (auto j:v[i])
				ans[max(++now,a[i])].push_back(j);
			v[i].clear();
		}
		long long ansx=0,ansy=1,nowx=0,nowy;
		for (int i=1;i<=n;i++)
		{
			nowy=i;
			for (auto j:ans[i]) nowx+=j;
			if (ansx*nowy<ansy*nowx) ansx=nowx,ansy=nowy;
			ans[i].clear();
		}
		long long g=__gcd(ansx,ansy);
		printf("%lld/%lld\n",ansx/g,ansy/g);
	}
	return 0;
}