//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXN 30
using namespace std;
char name[MAXN];
int len, t;
int main()
{
	scanf("%d\n", &t);
	while (t--)
	{
		memset(name, 0, sizeof(name));
		gets(name);
		len = strlen(name);
		if (name[0] >= 'a' && name[0] <= 'z') name[0] -= 32;
		for (int i = 1; i < len; i++)
			if (name[i] >= 'A' && name[i] <= 'Z') name[i] += 32;
		puts(name);
	}
	return 0;
}
