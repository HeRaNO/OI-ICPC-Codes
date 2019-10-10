#include <bits/stdc++.h>
using namespace std;

int T;
long long x,y;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld %lld",&x,&y);
		puts(x>y+1?"Yes":"No");
	}
	return 0;
}