//Code By HeRaNO
#include <stack>
#include <cstring>
#include <iostream>
using namespace std;

stack <string> s;
string word;

int main()
{
	while (cin >> word)
		s.push(word);
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}
