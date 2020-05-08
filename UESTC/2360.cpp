#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int T,n,ans,top;
char s[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		if (!n){puts("0");continue;} // WTF???
		scanf("%s",s);ans=top=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='(') ++top;
			else if (top>0) --top;
			else ++ans;
		}
		printf("%d\n",ans+top);
	}
	return 0;
}