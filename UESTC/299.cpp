#include <bits/stdc++.h>
using namespace std;

int T,n,cnt;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);unsigned long long p=5;
		for (int i=1;i<n;i++) p*=3;
		printf("Case #%d: %llu\n",++cnt,p);
	}
	return 0;
}
