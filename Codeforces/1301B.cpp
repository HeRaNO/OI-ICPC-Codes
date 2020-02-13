#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int mx=1<<31,mn=~(1<<31);int k,ans=~(1<<31),t=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++)
		{
			if (!~a[i])
			{
				if(~a[i-1]&&i>1) mn=min(mn,a[i-1]),mx=max(mx,a[i-1]);
				if(~a[i+1]&&i<n) mn=min(mn,a[i+1]),mx=max(mx,a[i+1]);
			}
			else if (~a[i+1]&&i<n) t=max(t,abs(a[i]-a[i+1]));
		}
		k=(mx+mn)>>1;
		if (mx==1<<31) printf("0 0\n");
		else printf("%d %d\n",max(t,max(abs(k-mn),abs(k-mx))),k);
	}
	return 0;
}