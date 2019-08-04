#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
	for (int i=1;i<=12500;i++) s+="ULDR";
	random_shuffle(s.begin(),s.end());
	cout<<s<<'\n';
	return 0;
}