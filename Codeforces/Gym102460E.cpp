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
const int N=2000;
int k,L;

void solve()
{
	ll sum=k+N-1;
	if(L>=2000){puts("-1");return;}
	printf("1999\n-1 ");
	for(int i=2;i<N;++i)
	{
		ll t=min(1000000LL,sum);
		printf("%lld ",t);
		sum-=t;
	}
	puts("");
}

int main()
{
	int Test;cin>>Test;
	while(Test--)
	{
		scanf("%d%d",&k,&L);
		solve();
	}
	return 0;
}
