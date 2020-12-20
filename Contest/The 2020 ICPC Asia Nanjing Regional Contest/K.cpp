#include <bits/stdc++.h>
using namespace std;
int n,k;
int p[1000050];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)p[i]=i;
	if(k==0)return puts("-1"),0;
	if(n&1)
	{
		if(k&1)
		{
			int i=2;
			while(k>1)
			{
				swap(p[i],p[i+1]);
				k-=2;i+=2;
			}
		}
		else
		{
			int i=1;
			while(k)
			{
				swap(p[i],p[i+1]);
				k-=2;
				i+=2;
			}
		}
	}
	else
	{
		if(k&1)
		{
			int i=2;
			while(k>1)
			{
				swap(p[i],p[i+1]);
				k-=2;i+=2;
			}
		}
		else
		{
			int i=1;
			while(k)
			{
				swap(p[i],p[i+1]);
				k-=2;
				i+=2;
			}
		}
	}
	printf("%d",p[1]);
	for(int i=2;i<=n;++i)printf(" %d",p[i]);
  //  system("pause");
	return 0;
}
