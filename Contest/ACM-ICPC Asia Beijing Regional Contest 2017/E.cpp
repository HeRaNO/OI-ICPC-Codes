#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int MAXN=1e7+10,MAXM=4e7+10;
const int INF=~(1<<31),MOD=1e9+7;
const ll llINF=((1ll<<61));

int a[MAXN],b[MAXN],n,m,x;

int main()
{
	while(scanf("%d%d%d",&m,&n,&x)==3)
	{
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		memset(b,0,(n+1)*sizeof(int));
		sort(a+1,a+n+1);
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(!b[j])
				{
					if(m)
					{
						m--;
						b[j]=a[j]-1;
					}
				}
				else b[j]--;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(b[i])ans++;
		printf("%d %d\n",m,ans);
	}
	return 0;
}