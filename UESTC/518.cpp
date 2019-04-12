#include <bits/stdc++.h>
using namespace std;

int T,a,b,c;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&a,&b,&c);
		if (a+b==9) puts(c==9?"Yes":"No");
		else puts(c==a+b?"No":"Yes");
	}
	return 0;
}
