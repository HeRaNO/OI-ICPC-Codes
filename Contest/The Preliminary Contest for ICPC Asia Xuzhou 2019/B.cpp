#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int MAXN=1e5+10;
const int INF=0x7fffffff;
const int MOD=20100403;

cc_hash_table <int,int> mp;

int _find(int x)
{
	int m=mp[x];
	return m==x?m:mp[x]=_find(m);
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	while(q--)
	{
		int o,x;
		scanf("%d%d",&o,&x);
		if(o==1)
		{
			if(mp[x])continue;
			if(!mp[x+1])mp[x]=x;
			else mp[x]=_find(x+1);
			if(mp[x-1])mp[x-1]=_find(x);
		}
		else
		{
			if(_find(x)) printf("%d\n",_find(x)+1);
			else printf("%d\n",x);
		}
	}
}