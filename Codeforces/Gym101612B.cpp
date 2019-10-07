#include <bits/stdc++.h>
using namespace std;
#define ll long long
void Init()
{
	freopen("boolean.in","r",stdin);
	freopen("boolean.out","w",stdout);
}
char s[1005];
bool no[1005];
bool yes[1005];
ll ans=1;
bool flag;

int main()
{
	Init();
	scanf("%s",s);
	int n=strlen(s);
	bool NOT=false;
	for(int i=0;i<n;++i)
	{
		if(s[i]=='~'){NOT=true;continue;}
		char c=s[i];
		if(s[i]!='|')
		{
			if(NOT==true)
			{
				if(yes[c]==true)
				{
					flag=true;
				}
				no[c]=true;
				NOT=false;
			}
			else
			{
				if(no[c]==true)
				{
					flag=true;
				}
				yes[c]=true;
			}
		}
	}
	for(char i='A';i<='Z';++i)
	{
		if(no[i]||yes[i])
		{
			ans*=2LL;
		}
	}
	for(char i='a';i<='z';++i)
	{
		if(no[i]||yes[i])
		{
			ans*=2LL;
		}
	}
	if(!flag)ans--;
	printf("%lld\n",ans);
	return 0;
}