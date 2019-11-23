#include <bits/stdc++.h>
using namespace std;

int T,ans;
char s[70];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s);
		int n=strlen(s),r=1;
		for (int i=0,j=n-1;i<=j&&r;i++,j--)
			if (s[i]!=s[j]) r=0;
		ans+=r;
	}
	printf("%d\n",ans);
	return 0;
}