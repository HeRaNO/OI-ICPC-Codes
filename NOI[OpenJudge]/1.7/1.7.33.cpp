//Code By HeRaNO
#include <cstdio>
#include <cstring>
using namespace std;
char st[101];
int main()
{
	gets(st);
	int i = 0, j = strlen(st) - 1;
	while ((j > i) && (st[i] == st[j]))
		i++, j--;
	if (j <= i) printf("yes\n");
	else printf("no\n");
	return 0;
}

