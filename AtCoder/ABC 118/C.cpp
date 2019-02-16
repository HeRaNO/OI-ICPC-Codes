#include <bits/stdc++.h>
using namespace std;

int n,ans,x;

inline int gcd(int a,int b){return !b?a:gcd(b,a%b);}

int main()
{
	scanf("%d",&n);scanf("%d",&ans);
	for (int i=2;i<=n;i++) scanf("%d",&x),ans=gcd(ans,x);
	printf("%d\n",ans);
	return 0;
}