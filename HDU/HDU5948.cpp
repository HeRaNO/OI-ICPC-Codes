#include <bits/stdc++.h>
using namespace std;

int T,a,b;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",max((a<<1)+b,(b<<1)+a));
	}
	return 0;
}