#include <bits/stdc++.h>
#define MAXV 10010
using namespace std;

int f[MAXV];
int n,m,x,y;

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		for (int i=n;i>=x;i--)
			f[i]=max(f[i],f[i-x]+y);
	}
	printf("%d\n",f[n]);
	return 0;
}
