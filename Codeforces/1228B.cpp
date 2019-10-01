#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

const long long M=1e9+7;
int h,w,s;
int r[MAXN],c[MAXN];
int mp[MAXN][MAXN];
long long ans;

long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,a=(a*a)%M) if (b&1) r=(r*a)%M;
	return r;
}

int main()
{
	scanf("%d%d",&h,&w);
	for (int i=1;i<=h;i++) scanf("%d",&r[i]);
	for (int i=1;i<=w;i++) scanf("%d",&c[i]);
	for (int i=1;i<=h;i++)
	{
		for (int j=1;j<=r[i];j++) mp[i][j]=1;
		mp[i][r[i]+1]=-1;
	}
	bool flag=true;
	for (int j=1;j<=w;j++)
	{
		for (int i=1;i<=c[j];i++)
		{
			if (mp[i][j]==-1){flag=0;break;}
			mp[i][j]=1;
		}
		if (flag==0) return puts("0"),0;
		if (mp[c[j]+1][j]==1) return puts("0"),0;
		mp[c[j]+1][j]=-1;
	}
	for (int i=1;i<=h;++i)
		for (int j=1;j<=w;++j)
			if (!mp[i][j]) ++s;
	printf("%lld\n",fpow(2,s));
	return 0;
}