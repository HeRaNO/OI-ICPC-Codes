//Code By HeRaNO
#include <cstring>
#include <iostream>
using namespace std;
string word;
int main()
{
	cin >> word;
	cout << word.length();
	while (cin >> word)
		cout << "," << word.length();
	return 0;
}
