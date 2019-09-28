#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
char s[2050][2050];
bitset <2050> b1[2050],b2[2050];
vector <int> v1[2050],v2[2050];

int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)v1[i].clear(),v2[i].clear(),b1[i].reset(),b2[i].reset();
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s[i]+1);
			for(int j=1;j<=n;++j)
			{
				if(s[i][j]=='P')b1[i][j]=1,v1[i].push_back(j);
				if(s[i][j]=='Q')b2[i][j]=1,v2[i].push_back(j);
			}
		}
		bool flag=true;
		for(int i=1;i<=n;++i)
		{
			for(auto j:v1[i])
			{
				if((b1[i]&b1[j])==b1[j])continue;
				flag=false;break;
			}
			if(!flag)break;
		}
		if(!flag){puts("N");continue;}
		flag=true;
		for(int i=1;i<=n;++i)
		{
			for(auto j:v2[i])
			{
				if((b2[i]&b2[j])==b2[j])continue;
				flag=false;break;
			}
			if(!flag)break;
		}
		if(!flag)puts("N");
		else puts("T");
	}
	return 0;
}