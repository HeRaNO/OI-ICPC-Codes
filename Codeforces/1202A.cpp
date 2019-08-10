#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int T,n,m;
char a[MAXN],b[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",a);scanf("%s",b);n=strlen(a);m=strlen(b);
		int pos=0;
		for(int i=m-1;i>=0;--i)
			if(b[i]=='1')
			{
				pos=m-i;
				break;
			}
		for(int i=n-pos;i>=0;--i)
			if(a[i]=='1')
			{
				printf("%d\n",n-pos-i);
				break;
			}
	}
	return 0;
}