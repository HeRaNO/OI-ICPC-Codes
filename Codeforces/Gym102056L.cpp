#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f,MAXN=1e5+10;
const double pi=acos(-1.0);

int a[MAXN];
int f[MAXN];
int cnt[2][2];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(a[u]^a[v])
		{
			f[u]++;
			f[v]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i])
		{
			if(f[i])cnt[1][1]++;
			else cnt[1][0]++;
		}
		else
		{
			if(f[i])cnt[0][1]++;
			else cnt[0][0]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		if(a[i])
		{
			ans+=cnt[1][0]+cnt[1][1]+f[i]-1;
			ans+=(cnt[0][1]-f[i])*2;
			if(f[i])
			ans+=cnt[0][0]*2;
			else ans+=cnt[0][0]*3;
		}
		else
		{
			ans+=cnt[0][0]+cnt[0][1]+f[i]-1;
			ans+=(cnt[1][1]-f[i])*2;
			if(f[i])ans+=cnt[1][0]*2;
			else ans+=cnt[1][0]*3;
		}
		printf("%d ",ans);
	}
	printf("\n");
	return 0;
}