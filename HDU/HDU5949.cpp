#include <bits/stdc++.h>
using namespace std;

int T;
char s[15];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int ans=0;
		scanf("%s",s);int n=strlen(s);
		for (int i=0;i<n;i++)
		{
			int x;
			if (s[i]=='H') x=1;
			if (s[i]=='C') x=12;
			if (s[i]=='O') x=16;
			ans+=x;
		}
		printf("%d\n",ans);
	}
	return 0;
}