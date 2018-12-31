#include <cstdio>
#include <cstring>
#define MAXN 1000
using namespace std;

char a[MAXN];
int n;

int main()
{
	gets(a);
	n = strlen(a);
	for (int i = 0; i < n; i++)
		if (a[i] >= 'a' && a[i] < 'z') a[i]++;
		else if (a[i] == 'z') a[i] = 'a';
	puts(a);
	return 0;
}