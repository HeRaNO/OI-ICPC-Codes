#include <bits/stdc++.h>
using namespace std;

int T,n,m,x;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%d",&x);
		for (int i=1;i<=m;i++) scanf("%d",&x);
		puts(n<=m?"Yes":"No");
	}
	return 0;
}