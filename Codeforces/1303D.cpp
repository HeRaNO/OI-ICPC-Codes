#include <bits/stdc++.h>
using namespace std;

int T,n,cnt[55],_2[55],ans;
long long m,s;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(cnt,0,sizeof cnt);
		scanf("%lld %d",&m,&n);s=0;ans=0;
		for (int i=1,x;i<=n;i++)
		{
			scanf("%d",&x);s+=x;
			for (int j=0;j<30;j++)
				if (x&(1<<j))
				{
					++cnt[j];break;
				}
		}
		if (s<m){puts("-1");continue;}int h=0;
		for (int i=0;i<50;i++) _2[i]=(m>>i)&1,h=i;
		for (int i=0;i<=h;i++)
		{
			if (cnt[i]>=_2[i])
			{
				cnt[i+1]+=((cnt[i]-_2[i])>>1);
				continue;
			}
			for (int j=i+1;j<50;j++)
				if (cnt[j])
				{
					ans+=j-i;--cnt[j];
					for (int k=j-1;k>i;--k) ++cnt[k];
					cnt[i]+=2;
					break;
				}
		}
		printf("%d\n",ans);
	}
	return 0;
}