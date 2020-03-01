#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,m,a[MAXN],p[MAXN],mx[MAXN],mn[MAXN];

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		a[i]=i,p[i]=i;
		mx[i]=mn[i]=i;
	}
	while (m--)
	{
		int x;scanf("%d",&x);
		int pos=p[x],pre=pos-1;
		if (pre)
		{
			--p[x];++p[a[pre]];
			swap(a[pos],a[pre]);
			mx[a[pos]]=max(mx[a[pos]],p[a[pos]]);
			mx[a[pre]]=max(mx[a[pre]],p[a[pre]]);
			mn[a[pos]]=min(mn[a[pos]],p[a[pos]]);
			mn[a[pre]]=min(mn[a[pre]],p[a[pre]]);
		}
	}
	for (int i=1;i<=n;i++) printf("%d %d\n",mn[i],mx[i]);
	return 0;
}