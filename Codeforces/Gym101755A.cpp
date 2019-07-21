#include <bits/stdc++.h>
using namespace std;

int s,g;

int main()
{
	scanf("%d %d",&s,&g);
	if (s%g) return puts("-1");
	if (s/g==1) return puts("-1");
	printf("%d %d\n",g,(s/g-1)*g);
	return 0;
}