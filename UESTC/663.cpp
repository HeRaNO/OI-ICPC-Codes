#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		int n;scanf("%d",&n);double ans=0;
		for (int i=1;i<=n;i++) ans+=(double)n/(n-i+1);
		printf("%.2lf\n",ans);
	}
	return 0;
}