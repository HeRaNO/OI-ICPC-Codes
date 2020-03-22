#include <bits/stdc++.h>
using namespace std;

char s[105];

int main(int argc, char const *argv[])
{
	int n,cas=0;
	while (scanf("%d",&n)==1)
	{
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			int now=0;
			scanf("%s",s);int m=strlen(s);
			for (int j=0;j<m;j++) now+=s[j];
			ans=max(ans,now);
		}
		printf("Case %d: %d\n",++cas,ans);
	}
	return 0;
}