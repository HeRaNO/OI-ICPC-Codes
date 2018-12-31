//Code By HeRaNO
#include<cstring>
#include<iostream>
using namespace std;
int l, n;
string s1, s2;
int main()
{
	cin >> s1;
	cin >> s2;
	l = s2.find(s1);
	n = s1.find(s2);
	if (l >= 0 || s1 == s2)
		cout << s1 << " is substring of " << s2;
	else if (n >= 0 && s1 != s2)
		cout << s2 << " is substring of " << s1;
	else
		cout << "No substring";
	return 0;
}
