#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1010
using namespace std;

char a[MAXN];
int n;

int main()
{
	scanf("%s", a);
	n = strlen(a);
	sort(a, a + n);
	puts(a);
	return 0;
}