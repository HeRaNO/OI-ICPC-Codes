#include <bits/stdc++.h>
using namespace std;

int T,n,k;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&k);
		puts((n>=1LL*k*k&&!((n&1)^(k&1)))?"YES":"NO");
	}
	return 0;
}