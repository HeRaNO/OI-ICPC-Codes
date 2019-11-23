#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T,n,x,a,b;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d %d",&n,&x,&a,&b);
		printf("%d\n",min(abs(b-a)+x,n-1));
	}
	return 0;
}