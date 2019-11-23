#include <bits/stdc++.h>
using namespace std;

long long n,ans;

int main()
{
	cin>>n;
	while (n)
	{
		for (long long i=n/2+1;i<=n;++i) ans+=i;
		n>>=2;
	}
	cout<<ans<<endl;
	return 0;
}