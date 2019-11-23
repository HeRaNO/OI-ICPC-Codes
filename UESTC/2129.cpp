#include <bits/stdc++.h>
using namespace std;

int n,m,k,a[1010];

bool cmp(int a,int b){return a>b;}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	printf("%d\n",a[k]);
	return 0;
}