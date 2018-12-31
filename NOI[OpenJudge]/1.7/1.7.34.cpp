//Code By HeRaNO
#include <cstring>
#include <iostream>
using namespace std;
string str;
int main()
{
	cin >> str;
	for (int i = 2; i <= str.length(); i++)
	{
		for (int j = 0; j < str.length() - i + 1; j++)
		{
			bool have = true;
			for (int k = j; k < j + i / 2; k++)
				if (str[k] != str[i + 2 * j - k - 1])
				{
					have = false;
					break;
				}
			if (have)
			{
				for (int k = j; k <= j + i - 1; k++) cout << str[k];
				cout << endl;
			}
		}
	}
	return 0;
}
