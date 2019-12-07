#include <bits/stdc++.h>
using namespace std;

int T,n;
char s[100005];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s);n=strlen(s);bool f=true;
		if (s[0]=='?')
		{
			if (s[1]>='a'&&s[1]<='c')
				s[0]=(s[1]-'a'+1)%3+'a';
			else s[0]='a';
		}
		if (s[n-1]=='?')
		{
			if (s[n-2]!='?') s[n-1]=(s[n-2]-'a'+1)%3+'a';
		}
		else
		{
			if (s[n-1]==s[n-2]) f=false;
		}
		for (int i=1;i<n-1&&f;i++)
			if (s[i]=='?')
			{
				if (s[i+1]>='a'&&s[i+1]<='c')
				{
					for (int j='a';j<='c';j++)
						if (s[i-1]!=j&&j!=s[i+1])
						{
							s[i]=j;break;
						}
					if (s[i]=='?') f=false;
				}
				else s[i]=(s[i-1]-'a'+1)%3+'a';
			}
			else
			{
				if (s[i-1]==s[i]) f=false;
			}
		if (s[n-1]=='?')
			s[n-1]=(s[n-2]-'a'+1)%3+'a';
		if (f) puts(s);
		else puts("-1");
	}
	return 0;
}