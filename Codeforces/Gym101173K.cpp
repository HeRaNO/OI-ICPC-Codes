#include <bits/stdc++.h>
#define MAXN 300005
using namespace std;

char s[MAXN];
int n,ans[MAXN];

inline void push(int x){ans[++ans[0]]=x;return ;}

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	if (n==3)
	{
		if (s[1]==s[2]&&s[2]==s[3])
		{
			puts("1");
			puts("1");
		}
		else puts("0");
		return 0;
	}
	for (int i=1;i<=n;i+=3)
	{
		int a=s[i]-'0',b=s[i+1]-'0',c=s[i+2]-'0',d=s[i+3]-'0',e=s[i-1]-'0';
		if (a==b&&b==c)
		{
			if (i==1)
			{
				if (a==0)
				{
					if (!d)
					{
						push(i+1);
						s[i+1]=s[i+2]='1';
					}
					else
					{
						push(i+2);
						s[i+2]='1';s[i+3]='0';
					}
				}
				else
				{
					if (!d)
					{
						push(i+2);
						s[i+2]='0';s[i+3]='1';
					}
					else
					{
						push(i+1);
						s[i+1]=s[i+2]='0';
					}
				}
			}
			else
			{
				if (a==0)
				{
					if (!e)
					{
						push(i);
						s[i]=s[i+1]='1';
					}
					else
					{
						push(i+1);
						s[i+1]=s[i+2]='1';
					}
				}
				else
				{
					if (!e)
					{
						push(i+1);
						s[i+1]=s[i+2]='0';
					}
					else
					{
						push(i);
						s[i]=s[i+1]='1';
					}
				}
			}
		}
		if (a==0&&b==1&&c==1)
		{
			push(i);
			s[i]='1';s[i+1]='0';
		}
		if (a==1&&b==0&&c==0)
		{
			push(i);
			s[i]='0';s[i+1]='1';
		}
		if (a==0&&b==0&&c==1)
		{
			push(i+1);
			s[i+1]='1';s[i+2]='0';
		}
		if (a==1&&b==1&&c==0)
		{
			push(i+1);
			s[i+1]='0';s[i+2]='1';
		}
	}
	printf("%d\n",ans[0]);
	for (int i=1;i<=ans[0];i++)
		printf("%d%c",ans[i],i==ans[0]?'\n':' ');
	return 0;
}