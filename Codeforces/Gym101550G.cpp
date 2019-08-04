#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;

int n,s,r=25,c;
char a[MAXN];

int f(int x)
{
	if (21<=x&&x<=25) return 2;
	if (16<=x&&x<=20) return 3;
	if (11<=x&&x<=15) return 4;
	return 5;
}

int main()
{
	scanf("%s",a);n=strlen(a);
	for (int i=0;i<n;i++)
	{
		if (!r) return puts("Legend"),0;
		if (a[i]=='W')
		{
			++c;++s;
			if (c>=3&&r>=6) ++s;
			if (s>f(r)) s-=f(r--);
		}
		else
		{
			c=0;
			if (r<=20)
			{
				if (s==0)
				{
					s=f(++r)-1;
				}
				else --s;
				if (r==21){r=20;s=0;}
			}
		}
	}
	if (r) printf("%d\n",r);
	else puts("Legend");
	return 0;
}