#include <bits/stdc++.h>
using namespace std;

int n,x,ne,po;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (x%2==0) printf("%d\n",x/2);
		else
		{
			if (x<0)
			{
				if (ne) printf("%d\n",(x-1)/2),ne=0;
				else printf("%d\n",x/2),ne=1;
			}
			else
			{
				if (po) printf("%d\n",(x+1)/2),po=0;
				else printf("%d\n",x/2),po=1;
			}
		}
	}
	return 0;
}