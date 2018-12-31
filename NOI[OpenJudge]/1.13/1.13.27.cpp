//Code By HeRaNO
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

char int_string(int n)
{
	char s = n + 48;
	return s;
}

int string_int(char s)
{
	return s - 48;
}

int main()
{
	string s;
	cin >> s;
	string ans = "";
	int u = 0;
	int i;
	bool f = false;
	for (i = 0; i <= s.size() - 1; i++)
	{
		u = u * 10 + string_int(s[i]);
		int t = u / 13;
		u %= 13;
		if (t != 0) f = true;
		if (f) ans += int_string(t);
	}
	if (ans != "") cout << ans << endl;
	else cout << 0 << endl;
	cout << u << endl;
	return 0;
}
