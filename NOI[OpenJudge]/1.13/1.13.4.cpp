//Code By HeRaNO
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int a[27], i, j, len;
	char st[110];
	for (i = 0; i < 26; i++)a[i] = 0;
	for (i = 0; i < 4; i++)
	{
		gets(st);
		len = strlen(st);
		for (j = 0; j < len; j++)
			if (st[j] >= 'A' && st[j] <= 'Z') a[st[j] - 'A']++;
	}
	int max = 0;
	for (i = 0; i < 26; i++)
		if (a[i] > max)max = a[i];
	for (i = max; i > 0; i--)
	{
		for (j = 0; j < 26; j++)
		{
			if (a[j] >= i)printf("* ");
			else printf("  ");
		}
		printf("\n");
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
	return 0;
}
