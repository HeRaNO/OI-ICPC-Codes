#include <bits/stdc++.h>
using namespace std;

int T,a,b;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",(a+b-1)/b*b-a);
	}
	return 0;
}