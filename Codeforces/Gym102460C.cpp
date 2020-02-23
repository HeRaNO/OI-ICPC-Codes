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
const int N=55;
ll a[N];

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	bool f=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			for(int k=1;k<=n;++k)
			{
				if(i==j||i==k||k==j)continue;
				ll t=(a[i]-a[j])/a[k];
				if(t*a[k]!=a[i]-a[j])f=0;
			}
		}
	}
	puts(f?"yes":"no");
	return 0;
}
