#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,k;
char a[MAXN],b[MAXN];

int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",a);int x=a[k-1]-'0';bool p=true,q=false;
	for (int i=0;i<n;i++)
	{
		b[i]=a[i%k];
		if (p&&!q&&b[i]<a[i]){p=false;break;}
		if (b[i]>a[i]) q=true;
	}
	if (!p)
	{
		int x=a[k-1]-'0'+1;a[k-1]=x%10+'0';
		int p=k-1;
		while(x==10)
		{
			x=a[--p]-'0'+1;
			a[p]=x%10+'0';
		}
		for(int i=0;i<n;i++) b[i]=a[i%k];
	}
	printf("%d\n",n);puts(b);
	return 0;
}