#include <bits/stdc++.h>
using namespace std;

int T,a[3],cnt;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&a[0],&a[1],&a[2]);
		printf("Case #%d:\n",++cnt);
		sort(a,a+3);
		do
			printf("%d %d %d\n",a[0],a[1],a[2]);
		while (next_permutation(a,a+3));
	}
	return 0;
}
