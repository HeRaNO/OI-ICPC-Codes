#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=4e5+10;
const int MOD=1e9+7;

char mp[205][205];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int h,w;
		scanf("%d%d",&h,&w);
		if(h&1&&w&1)
			for(int i=1;i<=h;i++)
			{
				for(int j=1;j<=w;j++)
					printf("(");
				printf("\n");
			}
		else if((h&1)||(w&1))
		{
			if(h&1)
			{
				for(int i=1;i<=h;i++)
				{
					for(int j=1;j<=w;j++)
						if(j&1)printf("(");
					else printf(")");
					printf("\n");
				}
			}
			else
			{
				for(int i=1;i<=h;i++)
				{
					for(int j=1;j<=w;j++)
						if(i&1)printf("(");
					else printf(")");
					printf("\n");
				}
			}
		}
		else
		{
			if(min(h,w)>6)
				for(int i=1;i<=h;i++)
				{
					for(int j=1;j<=w;j++)
					{
						if(i==1||j==1)printf("(");
						else if(i==h||j==w)printf(")");
						else if((i+j)&1)printf(")");
						else printf("(");
					}
					printf("\n");
				}
			else if(min(h,w)<=6)
			{
				if(h>=w)
				for(int i=1;i<=h;i++)
				{
					for(int j=1;j<=w;j++)
					{
						if(j==1)printf("(");
						else if(j==w)printf(")");
						else if((j+i)&1)printf("(");
						else printf(")");
					}
					printf("\n");
				}
				else
				{
					for(int i=1;i<=h;i++)
					{
						for(int j=1;j<=w;j++)
						{
							if(i==1)printf("(");
							else if(i==h)printf(")");
							else if((j+i)&1)printf("(");
							else printf(")");
						}
						printf("\n");
					}
				}
			}
		}
	}
	return 0;
}