#include <bits/stdc++.h>
#define MAXN 20
using namespace std;

char a[MAXN];
int n,T,pre[MAXN];
long long dp[1<<16];

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	scanf("%d",&T);
	for (int kas=1;kas<=T;kas++)
	{
		memset(dp,0,sizeof dp);memset(pre,0,sizeof pre);
		scanf("%d",&n);scanf("%s",a);dp[0]=1;
		for (int i=0;i<n;i++) if (a[i]=='1') dp[1<<i]=1;
		for (int i=0;i<n;i++)
		{
			scanf("%s",a);
			for (int j=0;j<n;j++) if (a[j]=='1') pre[j]|=(1<<i);
		}
		for (int i=0;i<(1<<n);i++)
			if (dp[i])
			{
				for (int j=0;j<n;j++)
					if (((i&pre[j])||dp[1<<j])&&!(i&(1<<j)))
						dp[i|(1<<j)]+=dp[i];
			}
		printf("Case %d: %lld\n",kas,dp[(1<<n)-1]>>1);
	}
	return 0;
}