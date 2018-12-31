//Code By HeRaNO
#include <cstdio>
#include <cstring>
using namespace std;
char b[55];
int a;
int main()
{
	gets(b);
	a = strlen(b);
	for (int i = 0; i < a; i++)
	{
		if (b[i] >= 'A' && b[i] <= 'Z')
		{
			if (b[i] == 'Z') b[i] = 'C';
			else if (b[i] == 'Y') b[i] = 'B';
			else if (b[i] == 'X') b[i] = 'A';
			else b[i] += 3;
		}
		else if (b[i] >= 'a' && b[i] <= 'z')
		{
			if (b[i] == 'x') b[i] = 'a';
			else if (b[i] == 'y') b[i] = 'b';
			else if (b[i] == 'z') b[i] = 'c';
			else b[i] += 3;
		}
		if (b[i] >= 'a' && b[i] <= 'z') b[i] -= 32;
		else  b[i] += 32;
	}
	for (int i = a - 1; ~i; i--)
		putchar(b[i]);
	return 0;
}

