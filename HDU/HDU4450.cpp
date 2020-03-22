#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	while(cin>>n&&n)
	{
		ll sum=0;
		for(int i=1;i<=n;++i){ll a;cin>>a;sum+=a*a;}
		cout<<sum<<endl;
	}
	return 0;
}