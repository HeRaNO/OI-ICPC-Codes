#include <cstdio>
#include <cstring>
#define MAXN 25
#define MAXW 2010
using namespace std;

int n,m,ans;
int a[MAXN];
bool dp[MAXW];
bool used[MAXN];

int mymax(int a,int b)
{
	return a>b?a:b;
}

void Backpack()
{
	memset(dp,0,sizeof(dp));
	int sum=0,best=0;
	dp[0]=true;
	for (int i=1;i<=n;i++)
		if (!used[i]) sum+=a[i];
	for (int i=1;i<=n;i++)
	{
		if (used[i]) continue;
		for (int j=sum;j>=a[i];j--)
			if (dp[j-a[i]]) dp[j]=true;
	}
	for (int i=1;i<=sum;i++) if (dp[i]) best++;
	ans=mymax(ans,best);
	return ;
}

void dfs(int dep,int start)
{
	if (dep==m+1)
	{
		Backpack();
		return ;
	}
	for (int i=start;i<=n;i++)
	{
		if (!used[i])
		{
			used[i]=true;
			dfs(dep+1,i+1);
			used[i]=false;
		}
	}
}

int main()
{
	freopen("weight.in","r",stdin);freopen("weight.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1,1);
	printf("%d\n",ans);
	return 0;
}