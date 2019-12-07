#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int n,a[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	printf("%d.00\n",a[1]-a[2]);
	return 0;
}