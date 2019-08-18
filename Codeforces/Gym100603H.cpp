#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

int T,n,a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);int s=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=n;i>=1;i-=2) s^=(a[i]-a[i-1]);
		puts(s?"TAK":"NIE");
	}
	return 0;
}