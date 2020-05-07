#include <bits/stdc++.h>
using namespace std;

int T,n,x;
set <int> s;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);s.clear();bool f=true;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&x);
			int p=(i+x)%n;if (p<0) p+=n;
			if (s.count(p)) f=false;
			s.insert(p);
		}
		puts(f?"YES":"NO");
	}
	return 0;
}