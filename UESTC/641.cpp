#include <bits/stdc++.h>
using namespace std;

int T,a,b,c;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&a,&b,&c);
		if (a+b==c) puts("+");
		else if (a-b==c) puts("-");
		else if (a*b==c) puts("*");
		else if (a/b==c) puts("/");
	}
	return 0;
}