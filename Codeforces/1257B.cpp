#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T,a,b;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&a,&b);
		if (a==1) puts(b<=1?"Yes":"No");
		else if (a<=3) puts(b<=3?"Yes":"No");
		else puts("Yes");
	}
	return 0;
}