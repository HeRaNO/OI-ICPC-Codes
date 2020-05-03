#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,x,top,sta[MAXN],a[MAXN],ans[MAXN],in[MAXN],out[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		in[i]=i;out[i]=n;
		while (top&&a[sta[top]]>=a[i]) out[sta[top--]]=i-1;
		if (!top) in[sta[++top]=i]=1;
		else in[i]=sta[top]+1,sta[++top]=i;
	}
	for (int i=1,l;i<=n;i++)
	{
		l=out[i]-in[i]+1;
		ans[l]=max(ans[l],a[i]);
	}
	for (int i=n;i;i--) ans[i]=max(ans[i+1],ans[i]);
	for (int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}