#include <bits/stdc++.h>
using namespace std;

int T,a,b;

inline int gcd(int a,int b){return !b?a:gcd(b,a%b);}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&a,&b);
		int t=gcd(a,b);
		printf("%d %d\n",t,a*b/t);
	}
	return 0;
}
