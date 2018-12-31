//Code By HeRaNO
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1010
using namespace std;

string mymail, name, mail;
char password[MAXN];
int n;
bool output = false;

int main()
{
	cin >> mymail;
	cin >> n;
	while (n--)
	{
		cin >> name >> password >> mail;
		if (mymail == mail)
		{
			output = true;
			cout << name << " ";
			for (int i = 0; i < strlen(password); i++)
			{
				if (password[i] >= 'a' && password[i] <= 'z') password[i] -= 32;
				else if (password[i] >= 'A' && password[i] <= 'Z') password[i] += 32;
			}
			puts(password);
		}
	}
	if (!output) cout << "empty" << endl;
	return 0;
}
