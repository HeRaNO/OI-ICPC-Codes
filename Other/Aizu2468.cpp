#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n,m,a[MAXN],cnt;
set <int> s;

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=n;i;i--)
	{
		if (!s.count(a[i]))
		{
			s.insert(a[i]);
			++cnt;
			printf("%d\n",a[i]);
		}
		if (cnt==m) break;
	}
	return 0;
}