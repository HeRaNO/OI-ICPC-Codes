#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int n,m,p,x=-1,y=-1,a[MAXN],b[MAXN];

int main()
{
	scanf("%d %d %d",&n,&m,&p);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<m;i++) scanf("%d",&b[i]);
	for (int i=0;i<n&&!~x;i++) if (a[i]%p) x=i;
	for (int i=0;i<m&&!~y;i++) if (b[i]%p) y=i;
	printf("%d\n",x+y);
	return 0;
}