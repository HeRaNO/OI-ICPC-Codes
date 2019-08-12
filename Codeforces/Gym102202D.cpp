#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f,MAXN=1e5+10;
const double pi=acos(-1.0);

int ans[MAXN],cnt;
string s[4]={"B+=B","A+=A","A+=B","B+=A"};

int main(){
	ll a,b;
	scanf("%lld%lld",&a,&b);
	ll tmp=__gcd(a,b);
	a/=tmp;
	b/=tmp;
	while(a!=b)
	{
		if(a%2==0)
		{
			a/=2;
			ans[++cnt]=0;
		}
		else if(b%2==0)
		{
			b/=2;
			ans[++cnt]=1;
		}
		else if(a>b)
		{
			a+=b;
			ans[++cnt]=2;
		}
		else
		{
			b+=a;
			ans[++cnt]=3;
		}
		tmp=__gcd(a,b);
		a/=tmp;
		b/=tmp;
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
	{
		cout<<s[ans[i]]<<endl;
	}
	return 0;
}