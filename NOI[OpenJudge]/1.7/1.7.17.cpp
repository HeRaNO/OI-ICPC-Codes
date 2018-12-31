//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXN 100
using namespace std;

char a[MAXN], b[MAXN];
int lena, lenb;
char c;

int main()
{
	while (true)
	{
		c = getchar();
		if (c == '\n') break;
		if (c >= 'a' && c <= 'z') a[lena++] = c;
		else if (c >= 'A' && c <= 'Z') a[lena++] = c + 32;
	}
	while (true)
	{
		c = getchar();
		if (c == '\n') break;
		if (c >= 'a' && c <= 'z') b[lenb++] = c;
		else if (c >= 'A' && c <= 'Z') b[lenb++] = c + 32;
	}
	if (lena != lenb)
	{
		printf("NO");
		return 0;
	}
	else
	{
		for (int i = 0; i < lena; i++)
			if (a[i] != b[i])
			{
				printf("NO");
				return 0;
			}
	}
	printf("YES");
	return 0;
}
