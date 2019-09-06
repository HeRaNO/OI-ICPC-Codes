#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

char s[MAXN];

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s);int n=strlen(s);int t=0,ans=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='0') ++t;
			else
			{
				int l=t+1,r=1,now=0;
				for (int j=i;j<n;j++)
				{
					now<<=1;now+=s[j]-'0';
					if (now>=r&&now<=l) ++ans;
					if (now>l) break;
					++l;++r;
				}
				t=0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}