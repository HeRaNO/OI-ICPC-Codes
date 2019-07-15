#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	int a[4];a[0]=a[1]=a[2]=a[3]=-1;
	a[n%4]=0;
	a[(n+1)%4]=1;
	a[(n+2)%4]=2;
	if (a[1]!=-1)
	{
		printf("%d A\n",a[1]);
	}
	else if (a[3]!=-1)
	{
		printf("%d B\n",a[3]);
	}
	else if (a[2]!=-1)
	{
		printf("%d C\n",a[2]);
	}
	else printf("%d D\n",a[0]);
	return 0;
}