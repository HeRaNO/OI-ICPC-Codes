#include <bits/stdc++.h>
using namespace std;

int a,b,c;

int main()
{
	while (true)
	{
		scanf("%d %d %d",&a,&b,&c);
		if (!a&&!b&&!c) break;
		if (a>b) swap(a,b);
		if (a>c) swap(a,c);
		if (b>c) swap(b,c);
		if (a<b&&b<c) printf("%d\n",b);
		else printf("%d\n",c);
	}
	return 0;
}