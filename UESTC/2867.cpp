#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,q,l=1,a[MAXN];
long long s,b[MAXN];

int main()
{
	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=q;i++) scanf("%lld",&b[i]);
	for (int i=1;i<=n;i++)
	{
		int c=1;
		for (;!(a[i]%3);a[i]/=3) c*=3;
		for (s+=c;l<=q&&b[l]<=s;l++) printf("%d%c",a[i]," \n"[l==q]);
	}
	return 0;
}