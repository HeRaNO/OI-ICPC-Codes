#include <bits/stdc++.h>
using namespace std;

string a[4],s[4];
int pt;

int main()
{
	cin>>a[1];cin>>a[2];cin>>a[3];
	for (int i=1;i<=3;i++)
		if (a[i]!="bubble"&&a[i]!="tapioka")
			s[++pt]=a[i];
	if (!pt) cout<<"nothing"<<endl;
	else
	{
		for (int i=1;i<=pt;i++) cout<<s[i]<<" ";
		cout<<endl;
	}
	return 0;
}