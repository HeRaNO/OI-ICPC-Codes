#include <bits/stdc++.h>
using namespace std;

int a,b,ans,ans2;

int main()
{
	scanf("%d %d",&a,&b);
	if (a==b) return puts("0"),0;
	for (int i=a;i!=b;)
	{
		++ans;i++;
		if (i==360) i=0;
	}
	for (int i=b;i!=a;)
	{
		++ans2;i++;
		if (i==360) i=0;
	}
	if (ans<ans2) printf("%d\n",ans);
	else if (ans==ans2) printf("180\n");
	else printf("%d\n",-ans2);
	return 0;
}
