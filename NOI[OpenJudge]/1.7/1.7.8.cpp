//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXN 40
using namespace std;
char a[MAXN];
int len;
char from, to;
int main()
{
	scanf("%s %c %c", a, &from, &to);
	len = strlen(a);
	for (int i = 0; i < len; i++)
		if (a[i] == from) a[i] = to;
	puts(a);
	return 0;
}
