#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;

int a[MAXN],q[MAXN];
bool num[MAXN];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		num[a[i]]=true;
	}
	for(int i=1;i<=m;i++)
		scanf("%d",&q[i]);
	for(int i=m;i>=1;i--)
	{
		if(num[q[i]])
		{
			num[q[i]]=false;
			printf("%d ",q[i]);
		}
	}
	bool f=true;
	for(int i=1;i<=n;i++)
		if(num[a[i]])
			printf("%d ",a[i]);
	return 0;
}