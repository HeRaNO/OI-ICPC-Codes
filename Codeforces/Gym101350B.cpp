#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if (a>=b) puts("FunkyMonkeys");
		else puts("WeWillEatYou");
	}
	return 0;
}