#include <cstdio>
using namespace std;

int n, p = 1, l;
char s[60];

int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= 10; i++) if (i * (i + 1) / 2 == n) l = i;
	for (int i = 1; i <= l; i++)
	{
		printf("%c", s[p]);
		p += i;
	}
	puts("");
	return 0;
}