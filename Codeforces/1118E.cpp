#include <bits/stdc++.h>
using namespace std;

int n,k,out;

int main()
{
	scanf("%d %d",&n,&k);
	if (1LL*k*(k-1)<n) return puts("NO"),0;
	puts("YES");
	for (int i=1;i<=k;i++)
		for (int j=i+1;j<=k;j++)
		{
			if (out<n){printf("%d %d\n",i,j);++out;}
			if (out<n){printf("%d %d\n",j,i);++out;}
			if (out==n) return 0;
		}
	return 0;
}
