//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXL 110
using namespace std;

char secret[MAXL];
char key[MAXL];
int a[MAXL], b[MAXL];
int len;
bool ok;

int main()
{
	gets(secret);
	gets(key);
	len = strlen(key);
	for (int i = 0; i < len; i++)
	{
		a[secret[i] - 'A']++;
		b[key[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (a[i])
		{
			ok = false;
			for (int j = 0; j < 26; j++)
				if (a[i] == b[j])
				{
					ok = true;
					b[j] = 0;
					break;
				}
			if (!ok)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}
