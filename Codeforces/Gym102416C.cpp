#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x7fffffff,MAXM=2e6+10,MAXN=2e5+10;
const int MOD=1e9+7;
const ll llINF=~(1ll<<63);

int main()
{
	ll a,d;
	cin>>a>>d;
	ll p=d/a;
	ll tmp=d%a;
	ll b=a+(tmp+p-1)/p;
	cout<<b;
	return 0;
}