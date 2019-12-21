#include <bits/stdc++.h>
#define MAXN 2005
using namespace std;

int n,m,x,a[MAXN];
set <int> s;
vector <int> b,c;

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		b.push_back(x);
	}
	sort(b.begin(),b.end());
	for (int j=0;j<n;j++) s.insert((b[j]-a[1]+m)%m);
	for (auto pp:s)
	{
		c.clear();
		for (int i=1;i<=n;i++) c.push_back((a[i]+pp)%m);
		sort(c.begin(),c.end());
		if (b==c) return printf("%d\n",pp),0;
	}
	return 0;
}