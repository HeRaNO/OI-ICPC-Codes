#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int T,n,cnt[MAXN],s[MAXN];
char a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(cnt,0,sizeof cnt);memset(s,0,sizeof s);
		scanf("%d",&n);scanf("%s",a+1);int p=1;
		for (int i=1;i<=n;i++)
		{
			if (a[i]-'0'){cnt[++cnt[0]]=p;p=1;}
			else ++p;
		}
		cnt[++cnt[0]]=p;
		for (int i=cnt[0];i;i--) s[i]=s[i+2]+cnt[i];
		long long ans=0;
		for (int i=1;i<cnt[0];i++) ans+=1LL*cnt[i]*s[i+1];
		for (int i=1;i<cnt[0];i++) ans-=cnt[i]+cnt[i+1]-1;
		printf("%lld\n",ans);
	}
	return 0;
}