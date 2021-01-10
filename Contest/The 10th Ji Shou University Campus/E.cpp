#include <bits/stdc++.h>
using namespace std;

inline bool ispri(int x)
{
	for (int i=2;i*i<=x;i++)
		if (!(x%i)) return false;
	return true;
}

vector <int> v;

int main()
{
	string name;
	int n;
	cin>>n;
	cin>>name;
	cout<<name;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if (!x) printf(" 0");
		else
		{
			int h=x/3600;x%=3600;
			int m=x/60;
			int s=x%60;
			printf(" %02d:%02d:%02d",h,m,s);
		}
	}
	puts("");
	return 0;
}