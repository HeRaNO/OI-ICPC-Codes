#include <cstring>
#include <iostream>
using namespace std;

string a, b, c;
int t;

int main()
{
	getline(cin, a);
	getline(cin, b);
	b[b.length() - 1] = ' ';
	t = b.find(" is ") + 2;
	c = b.substr(t + 1, b.length() - 1);
	cout << a << c;
	if (b[0] == 'I') b[0] = 'i';
	if (b[0] == 'Q') b[0] = '1';
	if (b[0] == 'T') b[0] = 't';
	cout << b.substr(0, t + 1) << '!' << endl;
	return 0;
}
