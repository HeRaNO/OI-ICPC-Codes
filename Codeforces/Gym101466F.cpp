#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n,a,b,c;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		if (a>b) swap(a,b);
		if (a>c) swap(a,c);
		if (b>c) swap(b,c);
		if (a+b<=c) return puts("NO"),0;
	}
	puts("YES");
	return 0;
}
