//Code By HeRaNO
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
	string s, s1, s2;
	getline(cin, s, ',');
	getline(cin, s1, ',');
	getline(cin, s2);
	if (s.find(s1) == string::npos || s.find(s2) == string::npos) cout << -1 << endl;
	else
	{
		int s1xb = s.find(s1);
		int s2xb = 0;
		while (s.find(s2, s2xb + 1) != string::npos) s2xb = s.find(s2, s2xb + 1);
		int cha = s2xb - (s1xb + s1.length());
		if (cha >= 0) cout << cha << endl;
		else cout << -1 << endl;
	}
	return 0;
}
