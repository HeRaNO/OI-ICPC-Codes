#include <bits/stdc++.h>
using namespace std;

int T,n,x,y;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&n,&x,&y);
		printf("%d %d\n",min(max(x+y-n+1,1),n),min(n,x+y-1));
	}
	return 0;
}