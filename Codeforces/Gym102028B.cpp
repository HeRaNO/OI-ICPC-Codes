#include <bits/stdc++.h>
using namespace std;
#define ll long long
int hp1,hp2,at1,at2;
ll ans;
inline ll gs(ll x){return x*(x+1)/2;}
inline ll gr(ll x){ll ret=1;while(gs(ret)<x)ret++;return ret;}

int main()
{
	int Test;scanf("%d",&Test);
	while(Test--)
	{
		scanf("%d%d%d%d",&hp1,&hp2,&at1,&at2);
		ll ra=gr(hp1),rb=gr(hp2),rc=gr(hp1+hp2);
		string fangan(rc,'B');
		if(at1*ra+at2*rc<=at2*rb+at1*rc)
		{
			ans=at1*ra+at2*rc;
			string tmp(rc,'A');
			for(int i=ra;i<rc;++i)tmp[i]='B';
			ll ta=gs(ra)-hp1,tc=gs(rc)-hp1-hp2;
			if(ta>tc)tmp[ta-1]='B';
			fangan=min(fangan,tmp);
		}
		if(at1*ra+at2*rc>=at2*rb+at1*rc)
		{
			ans=at2*rb+at1*rc;
			string tmp(rc,'B');
			for(int i=rb;i<rc;++i)tmp[i]='A';
			ll tb=gs(rb)-hp2,tc=gs(rc)-hp1-hp2,tt=tb-tc;
			int las;
			for(int i=0;i<ra;++i)
			{
				if(tb<i+1)continue;
				tmp[i]='A';
				tb-=(i+1),tt-=(i+1);
				las=i;
			}
			if(tt>0)
			{
				tmp[las]='B';
				tmp[las+tt]='A';
			}
			fangan=min(fangan,tmp);
		}
		printf("%lld ",ans);
		cout<<fangan<<endl;
	}
	return 0;
}