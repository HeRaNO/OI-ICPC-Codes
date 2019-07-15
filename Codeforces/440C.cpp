#include <bits/stdc++.h>
using namespace std;

long long n,a[17];

int dfs(long long n,int x)
{
	int num=n/a[x];n%=a[x];
	if (!n) return num*x;
	return num*x+min(x+dfs(a[x]-n,x-1),dfs(n,x-1));
}

int main()
{
	scanf("%lld",&n);int pt=0;
	for (int i=1;i<=16;i++) a[i]=a[i-1]*10+1;
	printf("%d\n",dfs(n,16));
	return 0;
}