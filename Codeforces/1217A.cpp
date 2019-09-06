#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		printf("%d\n",min(max((a-b+c+1)/2,0),c+1));
	}
	return 0;
}