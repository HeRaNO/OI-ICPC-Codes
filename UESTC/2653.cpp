#include <bits/stdc++.h>
using namespace std;

int T,n,k;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&k);
		puts((n/k)&1?"Kate":"Draw");
	}	
	return 0;
}
