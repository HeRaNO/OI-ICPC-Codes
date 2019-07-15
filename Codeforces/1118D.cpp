#include <bits/stdc++.h>
using namespace std;

int n,m,a[200010];
int l,r,mid,ans;long long s[200010];

bool cmp(int a,int b){return a>b;}

bool check(int k)
{
	memset(s,0,sizeof s);
	int pt=0,d=0;
	for (int i=1;i<=n;i++)
	{
		s[pt]+=max(a[i]-d,0);
		pt=(pt+1)%k;
		if (!pt) ++d;
	}
	long long ans=0;
	for (int i=0;i<k;i++) ans+=s[i];
	return ans>=m;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	l=1;r=n;ans=-1;
	while (l<=r)
	{
		mid=l+r>>1;
		if (check(mid)){r=mid-1;ans=mid;}
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}