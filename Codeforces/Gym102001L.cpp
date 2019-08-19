#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=1e6+10,INF=0x7fffffff;

ll k;
char s[70];

ll getnum(int r)
{
	ll ans=0;
	for(int i=1;i<=r;i++)
	{
		if(s[i]=='*')continue;
		ans*=2;
		ans+=s[i]-'0';
	}
	return ans;
}

int main()
{
	scanf("%lld",&k);
	scanf("%s",s+1);
	int sz=strlen(s+1),ans=0;
	while(getnum(sz)>k)
	{
		bool flag=false,tag=false;;
		for(int i=1;i<=sz;i++)
		{
			if(s[i]=='1')
			{
				if(flag)
				{
					s[i]='*';
					tag=true;
					break;
				}
				flag=true;
			}
		}
		if(!tag)
		{
			for(int i=1;i<=sz;i++)
				if(s[i]=='0')
				{
					s[i]='*';
					break;
				}
		}
		ans++;
	}
	printf("%d",ans);
	return 0;
}

