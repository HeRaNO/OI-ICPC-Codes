#include <bits/stdc++.h>
using namespace std;

int T;
char s[105];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s+1);
		int l=0,r=-1,cnt=0,n=strlen(s+1);
		for(int i=1;i<=n;i++)
			if(s[i]&1)
			{
				if (!l) l=i;
				r=i;
				cnt++;
			}
		printf("%d\n",r-l+1-cnt);
	}
	return 0;
}