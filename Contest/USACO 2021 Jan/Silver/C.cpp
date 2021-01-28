#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

int n,a[MAXN][MAXN],hans,vans;

int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++)
	{
		int s[2]={0,0};
		for (int j=1;j<=n;j++)
			s[j&1]+=a[i][j];
		hans+=max(s[0],s[1]);
	}
	for (int i=1;i<=n;i++)
	{
		int s[2]={0,0};
		for (int j=1;j<=n;j++)
			s[j&1]+=a[j][i];
		vans+=max(s[0],s[1]);
	}
	printf("%d\n",max(hans,vans));
	return 0;
}