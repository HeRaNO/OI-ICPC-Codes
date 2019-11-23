#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=300050;
const ll llINF=~(1ll<<63);
const int INF=~(1<<31);

char s[2];
set<ll> posh,posw;
multiset<ll>sh,sw;
set<ll>::iterator it;

int main()
{
	ll w,h,n;
	scanf("%lld%lld%lld",&w,&h,&n);
	posh.insert(0);
	posw.insert(0);
	posh.insert(h);
	posw.insert(w);
	sh.insert(h);
	sw.insert(w);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		ll tmp;
		scanf("%lld",&tmp);
		if(s[0]=='V')
		{
			posw.insert(tmp);
			it=posw.find(tmp);
			it++;
			ll r=*it;
			it--;
			it--;
			ll l=*it;
			sw.erase(sw.find(r-l));
			sw.insert(r-tmp);
			sw.insert(tmp-l);
			printf("%lld\n",(*sw.rbegin())*(*sh.rbegin()));
		}
		else
		{
			posh.insert(tmp);
			it=posh.find(tmp);
			it++;
			ll r=*it;
			it--;
			it--;
			ll l=*it;
			sh.erase(sh.find(r-l));
			sh.insert(r-tmp);
			sh.insert(tmp-l);
			printf("%lld\n",(*sw.rbegin())*(*sh.rbegin()));
		}
	}
	return 0;
}