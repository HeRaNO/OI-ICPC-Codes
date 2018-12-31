//Code By HeRaNO
#include <cstdio>
#include <cstring>
using namespace std;
char st[1001];
int i, len, pos = 0;
int main()
{
	gets(st);
	len = strlen(st);
	for (i = 0; i < len; i++)
		if (st[i] >= 'a' && st[i] <= 'z') st[i] -= 32;
	for (i = 0; i < len; i++)
		if (st[i] != st[i + 1])
		{
			printf("(%c,%d)", st[i], i + 1 - pos);
			pos = i + 1;
		}
	return 0;
}

