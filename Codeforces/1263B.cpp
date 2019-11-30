#include <bits/stdc++.h>
using namespace std;

int T,n,ans;
char s[15][5];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		ans=0;scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%s",s[i]);
		for (int i=1;i<n;i++)
			for (int j=1;j<=n;j++)
				if (i!=j&&strcmp(s[i],s[j])==0)
				{
					++ans;
					if (s[i][0]=='9') s[i][0]='0';
					else ++s[i][0];
					while (true)
					{
						bool f=false;
						for (int k=1;k<=n&&!f;k++)
							if (i!=k&&strcmp(s[i],s[k])==0) f=true;
						if (!f) break;
						if (s[i][0]=='9') s[i][0]='0';
						else ++s[i][0];
					}
				}
		printf("%d\n",ans);
		for (int i=1;i<=n;i++) puts(s[i]);
	}
	return 0;
}