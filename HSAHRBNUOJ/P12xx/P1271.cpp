#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXN 5005
using namespace std;

const int m[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};

int a[MAXN],n;
int sy,sm,sd,sh,sM;
int edy,edm,edd,edh,edM;

void quit(int x)
{
	printf("%d\n",x-1);exit(0);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);sort(a+1,a+n+1);
	scanf("%d-%d-%d-%d:%d",&sy,&sm,&sd,&sh,&sM);
	scanf("%d-%d-%d-%d:%d",&edy,&edm,&edd,&edh,&edM);
	for (int i=1;i<=n;i++)
	{
		sM+=a[i];int add=0,lpy;
		if (sM>=60){sh+=sM/60;sM%=60;}
		if (sh>=24){add=sh/24;sh%=24;}
		while (add--)
		{
			if (sy%100==0)
			{
				if (sy%400==0) lpy=1;
				else lpy=0;
			}
			else
			{
				if (sy%4==0) lpy=1;
				else lpy=0;
			}
			++sd;
			if (sd>m[lpy][sm]){++sm;sd=1;}
			if (sm>12){++sy;sm=1;}
		}
		if (sy<edy) continue;
		else if (sy>edy) quit(i);
		else
		{
			if (sm<edm) continue;
			else if (sm>edm) quit(i);
			else
			{
				if (sd<edd) continue;
				else if (sd>edd) quit(i);
				else
				{
					if (sh<edh) continue;
					else if (sh>edh) quit(i);
					else
					{
						if (sM<=edM) continue;
						else quit(i);
					}
				}
			}
		}
	}
	printf("%d\n",n);
	return 0;
}