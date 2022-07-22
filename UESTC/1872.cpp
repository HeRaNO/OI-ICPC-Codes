#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a;
	scanf("%d %d",&n,&a);
	bool f=false;
	for (int i=0;i<=a&&!f;i++)
		if ((n-i)%500==0) f=true;
	puts(f?"Yes":"No");
	return 0;
}