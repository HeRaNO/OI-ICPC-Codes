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
	printf("1 %d\n",n-1);
	return 0;
}