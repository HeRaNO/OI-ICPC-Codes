#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int T,n,p,q,x,a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&n,&p,&q);
		for (int i=1;i<=p;i++) scanf("%d",&x),a[x]=1;
		for (int i=1;i<=q;i++) scanf("%d",&x),a[x]=2;
		puts(a[n]==1?"YES":"NO");
	}
	return 0;
}