//Code By HeRaNO
#include <cstdio>
#include <cstring>
using namespace std;

char a[100];
int i, len;

int main()
{
	gets(a);
	len = strlen(a);
	for (i = 0; i < len; i++)
		if (a[i] >= 97 && a[i] <= 122)
			a[i] -= 32;
	puts(a);
	return 0;
}
