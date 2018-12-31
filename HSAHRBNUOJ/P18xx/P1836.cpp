#include <map>
#include <cstring>
#include <iostream>
using namespace std;

int n, page, T;
string word;
map <string, int> m;
map <string, int> :: iterator it;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> word;
		cin >> page;
		m.insert(make_pair(word, page));
	}
	cin >> T;
	while (T--)
	{
		cin >> word;
		it = m.find(word);
		cout << it->second << endl;
	}
	return 0;
}
