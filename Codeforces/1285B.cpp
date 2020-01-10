#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,a[MAXN];
long long s[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);int pos=0;
		for (int i=1,x;i<=n;i++) scanf("%d",&x),s[i]=s[i-1]+x;
		long long mn=0,mx=1LL<<63;
		for (int i=1;i<=n;i++)
		{
			if (mn>=s[i]) mn=s[i],pos=i;
			if (!pos&&i==n) continue;
			mx=max(mx,s[i]-mn);
		}
		puts(mx<s[n]?"YES":"NO");
	}
	return 0;
}