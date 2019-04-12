#include <bits/stdc++.h>
using namespace std;

int n,T,x,m,l,r,cnt[105];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);memset(cnt,0,sizeof cnt);
		for (int i=1;i<=n;i++) scanf("%d",&x),++cnt[x];
		for (int i=1;i<=100;i++) cnt[i]+=cnt[i-1];
		scanf("%d",&m);
		while (m--)
		{
			scanf("%d %d",&l,&r);
			if (!l) printf("%d\n",cnt[r]);
			else printf("%d\n",cnt[r]-cnt[l-1]);
		}
		puts("");
	}
	return 0;
}
