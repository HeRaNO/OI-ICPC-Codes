#include <bits/stdc++.h>
using namespace std;

int n;
char s[1000010];

int main()
{
	scanf("%d",&n);
	long long all=1LL*n*(n+1)/2;
	if (all&1) return puts("-1"),0;
	all=all/2;
	for (int i=n;i&&all;i--)
	{
		if (all>=i)
		{
			all-=i;
			s[i]='-';
		}
	}
	for (int i=1;i<=n;i++) putchar(!s[i]?'+':'-');
	puts("");
	return 0;
}