#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,T,l,r;
char s[MAXN];
bool vis[MAXN];
int pre[MAXN],suf[MAXN];

inline void Paint()
{
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			++ans;vis[i]=true;
			int p=i;
			while (p<=n&&s[p+1]>=s[i])
			{
				++p;
				if (s[p]==s[i]) vis[p]=true;
			}
			pre[i]=ans;
		}
		else pre[i]=pre[i-1];
	}
	memset(vis,false,sizeof vis);
	ans=0;
	for (int i=n;i;i--)
	{
		if (!vis[i])
		{
			++ans;vis[i]=true;
			int p=i;
			while (p&&s[p-1]>=s[i])
			{
				--p;
				if (s[p]==s[i]) vis[p]=true;
			}
			suf[i]=ans;
		}
		else suf[i]=suf[i+1];
	}
	return ;
}

int main()
{
	scanf("%d %d",&n,&T);
	scanf("%s",s+1);
	Paint();
	while (T--)
	{
		scanf("%d %d",&l,&r);
		printf("%d\n",pre[l-1]+suf[r+1]);
	}
	return 0;
}