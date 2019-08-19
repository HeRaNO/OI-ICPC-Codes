#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

struct doll
{
	int in,out,c;
	bool operator < (const doll &a)const{
		return c>a.c;
	}
};

doll a[MAXN];
int n,ans;
bool vis[MAXN];

int main()
{
	while (~scanf("%d",&n))
	{
		memset(vis,false,sizeof vis);
		for (int i=1;i<=n;i++) scanf("%d %d %d",&a[i].out,&a[i].in,&a[i].c);
		sort(a+1,a+n+1);ans=0;
		for (int i=1;i<=n;i++)
		{
			int mx=0,tar=0;
			for (int j=1;j<=n;j++)
				if (!vis[j]&&a[i].in>a[j].out&&a[j].out>mx)
				{
					mx=a[j].out;tar=j;
				}
			ans+=(a[i].in-mx)*a[i].c;vis[tar]=true;
		}
		printf("%d\n",ans);
	}
	return 0;
}