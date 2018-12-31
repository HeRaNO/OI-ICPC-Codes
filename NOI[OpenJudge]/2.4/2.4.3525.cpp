//Code By HeRaNO
#include <cstdio>
#define MAXN 100010
using namespace std;

int f[MAXN];
int n;

void pre_work()
{
	f[1] = 1;
	f[2] = 2;
	f[3] = 4;
	for (int i = 4; i <= MAXN; i++)
		f[i] = (f[i - 1] + f[i - 2] + f[i - 3]);
	return ;
}

int main()
{
	pre_work();
	while (~scanf("%d", &n) && n)
		printf("%d\n", f[n]);
	return 0;
}
