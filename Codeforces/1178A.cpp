#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int n,a[MAXN],s,now;
vector <int> ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),s+=a[i];
	s=s/2+1;now=a[1];ans.push_back(1);
	for (int i=2;i<=n;i++)
	{
		if (now>=s) break;
		if (a[1]>=a[i]*2) now+=a[i],ans.push_back(i);
	}
	if (now>=s)
	{
		printf("%d\n",ans.size());
		for (int i=0;i<ans.size();i++)
			printf("%d ",ans[i]);
		puts("");
	}
	else puts("0");
	return 0;
}