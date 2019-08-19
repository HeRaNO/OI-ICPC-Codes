#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int T,n,x,y;
long long ans,c[MAXN][2];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		memset(c,-1,sizeof c);ans=0LL;
		c[0][0]=c[0][1]=0;
		for (int i=1;i<=(n<<1);i++)
		{
			scanf("%d %d",&x,&y);
			if (x<1) ans+=1-x,x=1;
			if (x>n) ans+=x-n,x=n;
			if (y<1) ans+=1-y,y=1;
			if (y>2) ans+=y-2,y=2;
			++c[x][y-1];
		}
		for (int i=1;i<=n;i++)
		{
			c[i][0]+=c[i-1][0];c[i][1]+=c[i-1][1];
			for (int j=0;j<2;j++)
				if(c[i][j]<0&&c[i][j^1]>0)
				{
					long long k=min(-c[i][j],c[i][j^1]);
					c[i][j]+=k;c[i][j^1]-=k;
					ans+=k;
				}
			ans+=abs(c[i][0])+abs(c[i][1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}