#include <bits/stdc++.h>
#define MAXN 105
#define MAXL 2048
using namespace std;

int T,n,m,x,a[MAXN],s[MAXN];
int cnt[MAXL];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(cnt,0,sizeof cnt);
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
		for (int i=1;i<=n;i++)
			for (int j=i;j<=n;j++)
				cnt[s[j]^s[i-1]]=max(cnt[s[j]^s[i-1]],j-i+1);
		scanf("%d",&m);
		while (m--)
		{
			scanf("%d",&x);
			if (x<0) x=0;
			int ans=0,p=~(1<<31);
			for (int i=x;i<2048;i++)
				if (cnt[i])
				{
					p=i-x;
					ans=cnt[i];
					break;
				}
			for (int i=x;~i;i--)
				if (cnt[i])
				{
					if (x-i<p) ans=cnt[i];
					else if (x-i==p) ans=max(ans,cnt[i]);
					break;
				}
			printf("%d\n",ans);
		}
		puts("");
	}
	return 0;
}