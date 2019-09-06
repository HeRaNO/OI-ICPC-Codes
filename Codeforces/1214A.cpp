#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n,e,d;
	scanf("%d %d %d",&n,&d,&e);e*=5;
	int ans=n;
	for (int i=n%e;i<=n;i+=e) ans=min(ans,i%d);
	printf("%d\n",ans);
	return 0;
}