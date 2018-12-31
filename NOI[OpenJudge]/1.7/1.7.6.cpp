//Code By HeRaNO
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	string a;
	cin >> a;
	bool x = true;
	if (a == "auto" || a == "case" || a == "break" || a == "char" || a == "const" || a == "continue"
			|| a == "default" || a == "do" || a == "double" || a == "else" || a == "enum" || a == "extern"
			|| a == "float" || a == "for" || a == "goto" || a == "if" || a == "int" || a == "long" || a == "redister"
			|| a == "return" || a == "short" || a == "signed" || a == "sizeof" || a == "static" || a == "struct"
			|| a == "switch" || a == "typedef" || a == "union" || a == "unsigned" || a == "void" || a == "volatile"
			|| a == "while")
		x = false;
	for (int i = 0; i < a.length(); i++)
	{
		if (i == 0)
		{
			if (a[i] >= '0' && a[i] <= '9')
				x = false;
		}
		if (a[i] < '0' || (a[i] > '9' && a[i] < 'A') || (a[i] > 'Z' && a[i] < 'a' && a[i] != '_') || (a[i] > 'z'))
			x = false;
	}
	if (x) cout << "yes";
	else cout << "no";
	return 0;
}