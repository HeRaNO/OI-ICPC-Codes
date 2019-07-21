#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int n,k,cnt[MAXN],s,x;

int main()
{
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&x),++cnt[x];
	for (int i=1;i<=k;i++) s+=(cnt[i]&1);
	printf("%d\n",n-(s>>1));
	return 0;
}