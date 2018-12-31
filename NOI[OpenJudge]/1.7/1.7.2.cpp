//Code By HeRaNO
#include <cstdio>
#include <cstring>
using namespace std;

char a[100010];
int i, len;
int cnt[130];

int main()
{
	gets(a);
	len = strlen(a);
	for (i = 0; i < len; i++)
		cnt[a[i]]++;
	for (i = 0; i < len; i++)
	{
		if (cnt[a[i]] == 1)
		{
			printf("%c", a[i]);
			return 0;
		}
	}
	printf("no");
	return 0;
}
