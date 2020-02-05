#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int T,n,x,y,ans,l,r;
char s[MAXN];
map <pair<int,int>,int> mp;
map <pair<int,int>,int> :: iterator it;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);scanf("%s",s);mp.clear();
		x=0;y=0;mp.insert({{x,y},0});ans=~(1<<31);
		for (int i=1;i<=n;i++)
		{
			if (s[i-1]=='L') --x;
			if (s[i-1]=='R') ++x;
			if (s[i-1]=='U') ++y;
			if (s[i-1]=='D') --y;
			it=mp.find({x,y});
			if (it!=mp.end())
			{
				if (ans>i-it->second)
				{
					ans=i-it->second;
					l=it->second+1;r=i;
				}
				mp.erase(it);
				mp.insert({{x,y},i});
			}
			else mp.insert({{x,y},i});
		}
		if (ans==~(1<<31)) puts("-1");
		else printf("%d %d\n",l,r);
	}
	return 0;
}