#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

map <long long,int> mp;
map <long long,int> :: iterator it,itt;
int n,now,top;
long long x,y,sta[MAXN],cnt[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld %lld",&x,&y);
		it=mp.find(x);
		if (it==mp.end()) mp.insert(make_pair(x,1));
		else ++mp[x];
		it=mp.find(y+1);
		if (it==mp.end()) mp.insert(make_pair(y+1,-1));
		else --mp[y+1];
	}
	for (it=mp.begin();it!=mp.end();it++)
	{
		if (it!=mp.begin())
		{
			cnt[now]+=it->first-itt->first;
		}
		now+=it->second;itt=it;
	}
	for (int i=1;i<=n;i++) printf("%lld%c",cnt[i],i==n?'\n':' ');
	return 0;
}