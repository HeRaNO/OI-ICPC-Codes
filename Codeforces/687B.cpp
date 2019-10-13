#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int INF=~(1<<31),MAXN=3e5+10;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll tmp=1;
 
int main()
{
	int n;ll k;
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		ll c;
		scanf("%lld",&c);
		tmp=tmp*c/gcd(c,tmp);
		tmp=gcd(tmp,k);
		if(tmp==k)break;
	}
	if(k==tmp)puts("YES");
	else puts("NO");
	return 0;
}