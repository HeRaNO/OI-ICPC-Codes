#include <cstdio>
#include <cstring>
#define MAXN 1010

char num[MAXN];
int a[MAXN], len, x;
int div[MAXN];

int main()
{
	scanf("%s", num);
	len = strlen(num);
	if (len == 1)
	{
		if (num[0] == '1' || num[0] == '4')
		{
			puts("False");
			return 0;
		}
	}
	for (int i = 0; i < len; i++) a[i] = num[i] - '0';
	for (int i = 0; i < len; i++)
	{
		div[i] = (x * 10 + a[i]) / 4;
		x = (x * 10 + a[i]) % 4;
	}
	if (x == 2) puts("False");
	else puts("True");
	return 0;
}
