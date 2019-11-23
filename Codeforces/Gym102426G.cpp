#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x7fffffff,MAXM=2e6+10,MAXN=5e5+10;
const int MOD=1e9+7;
const ll llINF=~(1ll<<63);

ll a[MAXN];

void chai(ll x)
{
	for(int i=0;x;i++)
	{
		a[i]+=x&1;
		x>>=1;
	}
}

bool ok(ll x)
{
	for(int i=0;i<=60;i++)
		if((1ll<<i)>=x&&a[i])return true;
	return false;
}

void solve(ll x)
{
	for(int i=0;i<=60;i++)
		if((1ll<<i)>=x&&a[i])
		{
			a[i]--;
			chai((1ll<<i)-x);
			break;
		}
}

char s[50];

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		ll p;
		scanf("%lld",&p);
		bool z=0;
		if(s[0]=='f')chai(p);
		else
		{
			if(!ok(p))
				puts("ERROR!"),z=1;
			else
				solve(p);
		}
		if(!z)
		{
			for(int i=0;i<=10;i++)
				printf("%lld ",a[i]);
			puts("");
		}
	}
	return 0;
}