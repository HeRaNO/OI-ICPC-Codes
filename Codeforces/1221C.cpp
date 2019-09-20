#include <bits/stdc++.h>
using namespace std;

int T,c,m,x;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&c,&m,&x);
		printf("%d\n",min(min(c,m),(c+m+x)/3));
	}
	return 0;
}