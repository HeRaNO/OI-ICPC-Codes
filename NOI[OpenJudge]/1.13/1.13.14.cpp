//Code By HeRaNO
#include <cstdio>
using namespace std;

int table[] = {0, 100, 121, 144, 225, 400, 441, 484, 676, 900};
int n;

int main()
{
	scanf("%d", &n);
	printf("%d\n", table[n]);
	return 0;
}
