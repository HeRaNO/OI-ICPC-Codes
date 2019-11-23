#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,ans,a[MAXN],b[MAXN],c[MAXN];
set <int> s;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),c[a[i]]=i;
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	s.insert(c[b[n]]);
	for (int i=n-1;i;i--)
	{
		if (*s.begin()<c[b[i]]) ++ans;
		s.insert(c[b[i]]);
	}
	printf("%d\n",ans);
	return 0;
}