#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

char s[MAXN][15];
int T,n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%s",s[i]);
		if (!(n&1)) puts("No");
		else
		{
			bool f=true;
			for (int i=1;i<=n&&f;i++)
			{
				if ((i&1)&&s[i][0]!='#') f=false;
				if (!(i&1)&&s[i][0]=='#') f=false;
			}
			puts(f?"Yes":"No");
		}
	}
	return 0;
}