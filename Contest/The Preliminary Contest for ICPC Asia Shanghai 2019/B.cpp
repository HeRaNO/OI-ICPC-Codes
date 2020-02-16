#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=1e6+10,MAXM=1e6+10;
const int INF=~(1<<31),MOD=1e9+7;

int a[MAXN];
set<int> s;

int main()
{
	int t,n,m;
	scanf("%d",&t);
	for(int kase=1;kase<=t;kase++)
	{
		scanf("%d%d",&n,&m);s.clear();
		for(int i=1;i<=m;i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			auto it=s.find(l);
			if(it!=s.end())s.erase(it);
			else s.insert(l);
			it=s.find(r+1);
			if(it!=s.end())s.erase(it);
			else s.insert(r+1);
		}
		int ans=0,lst=0,now=0;
		for(auto it=s.begin();it!=s.end();it++)
		{
			if(now)ans+=*it-lst;
			now^=1;
			lst=*it;
		}
		printf("Case #%d: %d\n",kase,ans);
	}
	return 0;
}