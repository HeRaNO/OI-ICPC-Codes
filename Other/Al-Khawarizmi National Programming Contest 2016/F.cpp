// The origin data is wrong, so it can't pass...
// Data has been modified by forgottencsc, so it passed.
#include <bits/stdc++.h>
using namespace std;

struct mat
{
	long long p[50][50];
}g,tmp;

int T,n;long long cnt,ans;char s[50];
long long a[50][50];

inline mat mul(mat a,mat b)
{
	mat c;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			c.p[i][j]=0LL;
			for (int k=1;k<=n;k++) c.p[i][j]+=a.p[i][k]*b.p[k][j];
		}
	return c;
}

int main()
{
	scanf("%d",&T);
	for (int kas=1;kas<=T;kas++)
	{
		scanf("%d",&n);ans=0;cnt=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%s",s);
			for (int j=1;j<=n;j++)
			{
				a[i][j]=1e11;g.p[i][j]=0;
				if (s[j-1]=='1')
				{
					a[i][j]=1;g.p[i][j]=1;
				}
			}
			a[i][i]=0;
		}
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (a[i][j]<1e11)
					ans=max(ans,a[i][j]);
		tmp=g;
		for (int p=1;p<ans;p++) tmp=mul(g,tmp);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (ans==a[i][j]) cnt+=tmp.p[i][j];
		printf("Case #%d: %lld\n",kas,ans*cnt);
	}
	return 0;
}

// Here's the implementation of the std...

/*
#include <bits/stdc++.h>
using namespace std;

int T,n,a[50][50],ans,cnt;
char s[50];

int main()
{
	scanf("%d",&T);
	for (int kas=1;kas<=T;kas++)
	{
		memset(a,0x3f,sizeof a);
		scanf("%d",&n);ans=0;cnt=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%s",s);
			for (int j=1;j<=n;j++) if (s[j-1]&1) a[i][j]=1;
			if (a[i][i]!=1) a[i][i]=0;
		}
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (a[i][j]!=a[0][0])
					ans=max(ans,a[i][j]);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (a[i][j]==ans) ++cnt;
		printf("Case #%d: %lld\n",kas,ans*cnt);
	}
	return 0;
}
*/