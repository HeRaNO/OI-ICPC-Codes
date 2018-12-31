//Code By HeRaNO
#include <cstdio>
#include <cstring>
using namespace std;
char n[10];
int len;
int main()
{
	gets(n);
	len = strlen(n);
	for (int i = len - 1; ~i; i--)
		printf("%c ", n[i]);
	return 0;
}
