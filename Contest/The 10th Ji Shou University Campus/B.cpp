#include <bits/stdc++.h>
using namespace std;

int n,a[100];
vector <int> v;
set <int> s;

inline void Solve()
{
	int ans1=0,ans2=0;s.clear();
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=1;i<(1<<n);i++)
	{
		v.clear();
		int m=__builtin_popcount(i);
		for (int j=0;j<n;j++) if (i&(1<<j)) v.push_back(a[j]);
		for (int j=0;j<(1<<m);j++)
		{
			int a=0,b=0;
			for (int k=0;k<m;k++)
			{
				if (j&(1<<k)) a+=v[k];
				else b+=v[k];
			}
			if (a==b&&!s.count(a))
			{
				++ans1;s.insert(a);
				ans2=max(ans2,a);
			}
		}
	}
	if (!ans1) puts("0 0");
	else printf("%d %d\n",ans1,ans2);
	return ;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--) Solve();
	return 0;
}