#include <bits/stdc++.h>
using namespace std;

int T,a,b;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&a,&b);
		if (a>b) swap(a,b);
		if (b>(a<<1)){puts("NO");continue;}
		int t=b-a;b-=(t<<1);a-=t;
		if ((a+b)%3) puts("NO");
		else puts("YES");
	}
	return 0;
}