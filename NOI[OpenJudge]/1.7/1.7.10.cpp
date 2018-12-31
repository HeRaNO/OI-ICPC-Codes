//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXN 210
using namespace std;
char a[MAXN];
char password[130];
int len;
int main()
{
	gets(a);
	len = strlen(a);
	password['A'] = 'V';
	password['B'] = 'W';
	password['C'] = 'X';
	password['D'] = 'Y';
	password['E'] = 'Z';
	for (char a = 'F'; a <= 'Z'; a++)
		password[(int)a] = a - 5;
	for (int i = 0; i < len; i++)
	{
		if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] = password[a[i]];
	}
	puts(a);
	return 0;
}
