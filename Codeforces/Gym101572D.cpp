#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n,k,p,a[MAXN],dis[1<<20],ans[21],mx;
queue <int> q;
char s[21];

int main()
{
	memset(dis,-1,sizeof dis);
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for (int j=0;j<k;j++) a[i]=(a[i]<<1)|(s[j]-'0');
		q.push(a[i]);dis[a[i]]=0;
	}
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=0;i<k;i++)
		{
			int pp=x^(1<<i);
			if (dis[pp]!=-1) continue;
			q.push(pp);
			dis[pp]=dis[x]+1;
		}
	}
	for (int i=0;i<(1<<k);i++) if (dis[i]>dis[p]) p=i;
	while (p)
	{
		ans[++ans[0]]=p&1;p>>=1;
	}
	for (int i=k;i;i--) printf("%d",ans[i]);puts("");
	return 0;
}