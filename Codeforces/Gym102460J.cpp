#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define mp(a,b) make_pair((a),(b))
#define pb(x) push_back(x)
using namespace std;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
const int N=505;
int n,m;
bitset <N> a[20];
char s[N];

int main()
{
	int Test;cin>>Test;
	while(Test--)
	{
		int ans=inf;
		mem(s,0);
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;++i)
		{
			scanf("%s",s);
			a[i]=bitset<N>(s);
		}
		for(int st=0;st<(1<<m);++st)
		{
			bitset <N> tmp(0);
			int cnt=0;
			for(int i=0;i<m;++i)
			{
				if((1<<i)&st)cnt++,tmp|=a[i];
			}
			if(tmp.count()==n)ans=min(ans,cnt);
		}
		if(ans==inf)ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
