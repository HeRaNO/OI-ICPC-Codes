#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int T,n,k,cnt[MAXN];
long long x;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&k);
		memset(cnt,0,sizeof cnt);
		for (int i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			for (int j=0;j<60;j++,x/=k) cnt[j]+=x%k;
		}
		bool f=true;
		for (int i=0;i<60&&f;i++) if (cnt[i]>1) f=false;
		puts(f?"YES":"NO");
	}
	return 0;
}