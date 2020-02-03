#include <iostream>
#include <cstdio>
using namespace std;

int a = 0, f;
string s, w;
string::size_type i;

int main()
{
	cin >> w;
	w = " " + w + " ";
	for (i = 0; i < w.size(); i++)
		w[i] = toupper(w[i]);
	getline(cin, s);
	getline(cin, s);
	s = " " + s + " ";
	for (i = 0; i < s.size(); i++)
		s[i] = toupper(s[i]);
	for (i = s.find(w); i < s.size(); i = s.find(w, i + w.size() - 1), a++)
		if (!a) f = i;
	if (a) cout << a << ' ' << f;
	else cout << -1;
}