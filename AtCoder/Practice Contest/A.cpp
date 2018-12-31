#include <cstdio>
using namespace std;

int a, b, c;
char s[101];

int main()
{
	scanf("%d", &a);
	scanf("%d%d", &b, &c);
	scanf("%s", s);
	printf("%d %s\n", a + b + c, s);
	return 0;
}