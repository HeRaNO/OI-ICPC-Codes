#include <bits/stdc++.h>
using namespace std;

int n,now,ans;
char s[110];

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	{
		if (s[i]!='x')
		{
			if (now>=3) ans+=now-2;
			now=0;
		}
		else ++now;
	}
	if (now>=3) ans+=now-2;
	printf("%d\n",ans);
	return 0;
}