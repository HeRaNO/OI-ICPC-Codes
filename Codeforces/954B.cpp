#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int n,ans=~(1<<31);
char a[MAXN];

int main()
{
	scanf("%d",&n);
	scanf("%s",a+1);
	if (n==1) return puts("1"),0;
	for (int i=1;i<=n/2;i++)
	{
		bool f=true;
		for (int j=1;j<=i&&f;j++) if (a[j]!=a[j+i]) f=false;
		if (f) ans=min(ans,i+1+n-2*i);
		else ans=min(ans,n);
	}
	printf("%d\n",ans);
	return 0;
}