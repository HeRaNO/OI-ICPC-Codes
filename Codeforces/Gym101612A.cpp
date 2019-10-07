#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

const int w[]={6,2,5,5,4,5,6,3,7,6};
int n,f[MAXN];

int main()
{
	freopen("auxiliary.in","r",stdin);
	freopen("auxiliary.out","w",stdout);
	scanf("%d",&n);
	for (int j=0;j<=9;j++)
		for (int i=0;i<=n;i++)
			if (i>=w[j]&&(f[i-w[j]]||i-w[j]==0))
				f[i]=max(f[i],f[i-w[j]]+j);
	printf("%d\n",f[n]);
	return 0;
}