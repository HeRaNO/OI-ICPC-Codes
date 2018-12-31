//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXN 100
using namespace std;

char a[MAXN], b[MAXN];
int lena, lenb;

int main()
{
	gets(a);
	lena = strlen(a);
	gets(b);
	lenb = strlen(b);
	for (int i = 0; i < lena; i++)
		if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 32;
	for (int i = 0; i < lenb; i++)
		if (b[i] >= 'A' && b[i] <= 'Z') b[i] += 32;
	int res = strcmp(a, b);
	if (res > 0) printf(">");
	else if (!res) printf("=");
	else printf("<");
	return 0;
}
