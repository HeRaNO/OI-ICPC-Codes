#include <bits/stdc++.h>
using namespace std;

int T,x,n;
set <int> s;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			s.insert(x);
		}
		printf("%d\n",s.size());s.clear();
	}
	return 0;
}