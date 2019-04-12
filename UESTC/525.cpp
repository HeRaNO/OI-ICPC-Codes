#include <bits/stdc++.h>
using namespace std;

int T,n,m,p;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);p=0;
		for (int i=2;i<=n;i++) (p+=m)%=i;
		printf("%d\n",p+1);
	}
	return 0;
}
