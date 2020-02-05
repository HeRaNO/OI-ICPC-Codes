#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,m,mx,pos,a[MAXN<<1],p[MAXN],f[MAXN];

inline bool check(int x)
{
	f[1]=0;
	for (int i=2;i<=n;i++)
	{
		f[i]=f[i-1];
		if (f[i-1]>=p[i]-1) f[i]=p[i]+x;
		if (f[i-1]>=p[i]-x-1) f[i]=max(f[i],p[i]);
		if (i!=2&&f[i-2]>=p[i]-x-1) f[i]=max(f[i],p[i-1]+x);
	}
	if (f[n]>=min(m-1,m+p[1]-x-1)) return true;
	f[2]=max(p[2],x);
	for (int i=3;i<=n;i++)
	{
		f[i]=f[i-1];
		if (f[i-1]>=p[i]-1) f[i]=p[i]+x;
		if (f[i-1]>=p[i]-x-1) f[i]=max(f[i],p[i]);
		if (i!=3&&f[i-2]>=p[i]-x-1) f[i]=max(f[i],p[i-1]+x);
	}
	return f[n]>=min(m-1,m+p[2]-x-1);
}

int main()
{
	scanf("%d",&m);scanf("%d",&n);
	if (n==1) return printf("%d\n",m-1),0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i+n]=a[i]+m;
	}
	sort(a+1,a+(n<<1)+1);
	for (int i=1;i<=n;i++)
		if (mx<a[i+1]-a[i]-1)
		{
			mx=a[i+1]-a[i]-1;pos=i;
		}
	for (int i=1;i<=n;i++) p[i]=a[i+pos];
	for (int i=n;i;i--) p[i]-=p[1];
	int l=0,r=mx,ans;
	while (l<=r)
	{
		int mid=l+r>>1;
		if (check(mid)){ans=mid;r=mid-1;}
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}