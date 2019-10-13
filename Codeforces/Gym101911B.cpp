#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int INF=~(1<<31),MAXN=3e5+10;

int a[MAXN],b[MAXN];
int l[MAXN],r[MAXN];

int main()
{
	int n,h;
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
	}
	for(int i=1;i<=n;i++)
		a[i]=l[i]-r[i-1];
	for(int i=1;i<=n;i++)
		b[i]=r[i]-l[i];
	for(int i=1;i<=n+1;i++)
	{
		a[i]+=a[i-1];
		b[i]+=b[i-1];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int tmp=lower_bound(a+i,a+n+1,a[i]+h)-a-1;
		//cout<<l[i]<<" "<<r[i]<<" "<<l[tmp]<<" "<<r[tmp]<<" "<<a[i]<<" "<<a[tmp]<<" "<<b[tmp]-b[i-1]+h<<endl;
		ans=max(ans,b[tmp]-b[i-1]+h);
	}
	printf("%d",ans);
	return 0;
}