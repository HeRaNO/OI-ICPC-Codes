#include <bits/stdc++.h>
using namespace std;

int T,n,x,a[15];

void calc(int x)
{
	int i=0;for (;x;x>>=1,i++);++a[i];
	return ;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof a);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x<=2048) calc(x);
		}
		for (int i=1;i<=12;i++) a[i+1]+=a[i]/2;
		if (a[12]) puts("YES");
		else puts("NO");
	}
	return 0;
}