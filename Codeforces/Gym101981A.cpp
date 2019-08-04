#include <bits/stdc++.h>
using namespace std;

int n,k;

int main()
{
	scanf("%d %d",&n,&k);
	if (!n) return puts("Austin"),0;
	if (k==1)
	{
		if (n&1) puts("Adrien");
		else puts("Austin");
	}
	else puts("Adrien");
	return 0;
}