//Code By HeRaNO
#include <cstdio>
#include <cstring>
using namespace std;
int i, temp, mb, maxx, len;

int main()
{
	char a[1000];
	gets(a);
	len = strlen(a);
	for (i = 0; i < len; i++)
	{
		if (a[i] != ' ' && a[i] != '.')
			temp++;
		if (temp > maxx)
		{
			maxx = temp;
			mb = i;
			continue;
		}
		if (a[i] == ' ') temp = 0;
	}
	for (i = mb - maxx + 1; i <= mb; i++)
		printf("%c", a[i]);
	return 0;
}
