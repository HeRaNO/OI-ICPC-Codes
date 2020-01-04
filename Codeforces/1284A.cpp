#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a[100],b[100];int n,m,T;
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<m;i++) cin>>b[i];
	cin>>T;
	while (T--)
	{
		int y;
		cin>>y;--y;
		cout<<a[y%n]<<b[y%m]<<'\n';
	}
	return 0;
}