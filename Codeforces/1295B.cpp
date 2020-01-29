#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,x,ans,cnt[MAXN];
char s[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&x);ans=0;
		scanf("%s",s);
		for (int i=0,p=0;i<n;i++) p+=(s[i]=='0'?1:-1),cnt[i]=p;
		if (!cnt[n-1])
		{
			bool f=false;
			for (int i=0;i<n&&!f;i++)
				if (cnt[i]==x) puts("-1"),f=true;
			if (!f) puts("0");
		}
		else
		{
			if (!x) ++ans;
			for (int i=0;i<n;i++)
			{
				if (cnt[n-1]>0)
				{
					if ((x-cnt[i])%cnt[n-1]==0&&x>=cnt[i])
						++ans;
				}
				else
				{
					if ((x-cnt[i])%(-cnt[n-1])==0&&x<=cnt[i])
						++ans;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}