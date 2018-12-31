//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXN 100
using namespace std;
char a[MAXN];
int len;
int main()
{
	gets(a);
	len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 32;
		else if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 32;
	}
	puts(a);
	return 0;
}
