#include <bits/stdc++.h>
using namespace std;

int n,k;

int main()
{
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++)
		if (5*i*(i+1)/2+k>240) return printf("%d\n",i-1),0;
	printf("%d\n",n);
	return 0;
}