#include <bits/stdc++.h>
using namespace std;

int T,n,m,k;

int main(int argc, char const *argv[])
{
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++)
	{
		scanf("%d %d %d",&n,&m,&k);
		int t=ceil(log2(n))+ceil(log2(m))+ceil(log2(k));
		printf("Case #%d: %lld %d\n",cas,1LL*n*m*k-1,t);
	}
	return 0;
}
