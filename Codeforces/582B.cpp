#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=5010;
int f[maxn];
int a[maxn];
int num[maxn];
int n,t;
int ans=0;
int lim;
int maxnum=0;

int main()
{
	scanf("%d%d",&n,&t);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		num[a[i]]++;
		maxnum=max(maxnum,num[a[i]]);
	}
	lim=min(n/2,t)*n;
	if (n==1)
	{
		printf("%d",t);
		return 0;
	}
	for (int i=n+1;i<=lim;i++)
	{
		a[i]=a[i-n];
	}
	for (int i=1;i<=lim;i++) f[i]=1;
	for (int i=1;i<=lim;i++)
	{
		for (int j=1;j<i;j++)
		{
			if (a[j]<=a[i])
			{
				f[i]=max(f[i],f[j]+1);
			}
		}
	}
	for (int i=1;i<=lim;i++) ans=max(ans,f[i]);
	if (t<=(n/2))
		printf("%d",ans);
	else
		printf("%d",ans+(t-(n/2))*maxnum);
	return 0;
}