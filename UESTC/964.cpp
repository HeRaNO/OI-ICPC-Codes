#include <bits/stdc++.h>
using namespace std;

int n,d1,d2,f;
string p;

int main()
{
	cin>>n>>d1>>d2>>f;
	if (!f) cout.setf(ios::left);
	for (int i=1;i<=n;i++)
	{
		cin>>p>>f;
		cout<<setw(d1)<<p<<setw(d2)<<f<<'\n';
	}
	return 0;
}
