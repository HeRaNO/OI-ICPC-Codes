//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXL 210
#define MAXN 110
using namespace std;

char secret[MAXL];
char a[MAXN][MAXN];
int r, c, len;

int main()
{
	scanf("%d", &c);
	getchar();
	gets(secret);
	len = strlen(secret);
	r = len / c;
	for (int i = len - 1; ~i; i--) secret[i + 1] = secret[i];
	for (int i = 1; i <= r; i++)
	{
		int cnt = 0;
		if (i % 2)
		{
			for (int j = (i - 1) * c + 1; j <= i * c; j++)
				a[i][++cnt] = secret[j];
		}
		else
		{
			for (int j = i * c; j >= (i - 1)*c + 1; j--)
				a[i][++cnt] = secret[j];
		}
	}
	for (int i = 1; i <= c; i++)
		for (int j = 1; j <= r; j++)
			printf("%c", a[j][i]);
	printf("\n");
	return 0;
}
