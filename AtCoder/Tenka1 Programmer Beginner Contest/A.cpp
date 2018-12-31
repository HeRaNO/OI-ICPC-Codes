#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char s[100];
	scanf("%s", s);
	if (strlen(s) == 2) puts(s);
	else
	{
		putchar(s[2]);
		putchar(s[1]);
		putchar(s[0]);
	}
	return 0;
}