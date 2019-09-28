#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll l,r;
unsigned ll mi(unsigned ll a,unsigned ll b)
{
	unsigned ll ret=1;
	while(b)
	{
		if(b&1)ret=ret*a;
		a=a*a;
		b>>=1;
	}
	return ret;
}

int main()
{
	int T;cin>>T;
	while(T--)
	{
		scanf("%lld%lld",&l,&r);
		bitset <70> b1(l),b2(r);
		int t1=log(1.0*l)/log(2.0);
		int t2=log(1.0*r)/log(2.0);
		if(t2>t1)
		{
			cout<<mi(2,t2+1)-1<<endl;
		}
		else
		{
			int it=t1;
			for(;it>=0;--it)
			{
				if(b1[it]==b2[it])continue;
				break;
			}
			for(;it>=0;--it)
			{
				if(b1[it]==1||b2[it]==1)continue;
				b1[it]=1;
				if(b1.to_ullong()>b2.to_ullong())b1[it]=0;
			}
			cout<<(b1|b2).to_ullong()<<endl;
		}
	}
	return 0;
}