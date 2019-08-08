#include <bits/stdc++.h>
typedef long long ll;
const int MAXN=3e5+10;
using namespace std;

int a[MAXN],b[MAXN],tot;

int main()
{
	int n,m,k;
	scanf("%d%d%d",&k,&n,&m);
	a[0]=1;
	for(int i=1;i<=k;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==-1)
				a[i]=a[i-1];
		}
	bool flag=false;
	for(int i=1;i<k;i++)
		if(a[i+1]-a[i]<0)
		flag=true;
	if(n<k||flag)
	{
		cout<<"-1";
		return 0;
	}
	int res=n-k;
	for(int i=1;i<=k;i++)
	{
		int cnt=m;
		while(res)
		{
			if(cnt==a[i])break;
			b[++tot]=cnt;
			cnt--;
			res--;
		}
		b[++tot]=a[i];
	}
	if(res>0)
	{
		cout<<"-1";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",b[i]);
	}
	return 0;
}
