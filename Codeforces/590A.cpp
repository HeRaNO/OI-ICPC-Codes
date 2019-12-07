#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=1e5+10,INF=~(1<<31),MOD=1e9+7,mod=998244353;
const int MAXM=5e6+10;
const ll llINF=~(1ll<<63);
const double Pi=acos(-1.0);
#define lowbit(x) x&-x

int a[MAXM];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int cnt=0,l=INF,r=0,ans=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1]&&a[i]!=a[i+1]&&i<n)
			cnt++,l=min(l,i),r=max(r,i);
		else
		{
			if((r-l+1)%2)
			for(int j=l;j<=r;j++)
				a[j]=a[l-1];
			else
			{
				for(int j=l;j<=(l+r)/2;j++)
					a[j]=a[l-1];
				for(int j=(l+r)/2+1;j<=r;j++)
					a[j]=a[r+1];
			}
			l=INF;
			r=0;
			ans=max(ans,(cnt+1)/2);
			cnt=0;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}