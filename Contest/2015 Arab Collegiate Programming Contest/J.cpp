#include <bits/stdc++.h>
using namespace std;

map <string,string> mp;

int main()
{
	int n,T,k;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		string a,e,b;
		cin>>a>>e>>b;
		mp.insert({a,b});
	}
	cin>>T;
	while (T--)
	{
		cin>>k;
		for (int i=1;i<=k;i++)
		{
			string a,b;
			cin>>a;
			cout<<mp[a];
			if (i==k) cout<<'\n';
			else cout<<' ';
		}
	}
	return 0;
}