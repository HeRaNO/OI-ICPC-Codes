#include <bits/stdc++.h>
using namespace std;

int n,x;
long long cnt[2];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[i&1]+=(x>>1);
		cnt[i&1^1]+=(x>>1)+(x&1);
	}
	printf("%lld\n",min(cnt[0],cnt[1]));
	return 0;
}