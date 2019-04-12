#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int T,n,top,ans;
char a[MAXN],s[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);scanf("%s",a);top=0;ans=0;
		for (int i=0;i<n;i++)
		{
			if (a[i]=='0') s[++top]=a[i];
			else
			{
				if (!top) ++ans;
				else --top;
			}
		}
		printf("%d.000\n",top+ans);
	}
	return 0;
}
