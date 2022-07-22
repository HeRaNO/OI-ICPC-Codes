#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,m,pa=1,pb=1,cnt,a[MAXN],b[MAXN];

int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	while (pa<=n&&pb<=m)
	{
		if (a[pa]<b[pb]) ++pa;
		else if (b[pb]<a[pa]) ++pb;
		else ++cnt,++pa,++pb;
	}
	if (n==m&&cnt==n) puts("A equals B");
	else if (n>m&&cnt==m) puts("B is a proper subset of A");
	else if (m>n&&cnt==n) puts("A is a proper subset of B");
	else if (!cnt) puts("A and B are disjoint");
	else puts("I am confused!");
	return 0;
}