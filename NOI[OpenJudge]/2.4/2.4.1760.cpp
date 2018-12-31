//Code By HeRaNO
#include <cstdio>
#define MAXN 1000010
using namespace std;

int f[MAXN];
int n, t;

void pre_work()
{
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= MAXN; i++)
		f[i] = (f[i - 1] + f[i - 2]) % 1000;
	return ;
}

int main()
{
	pre_work();
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%d\n", f[n]);
	}
	return 0;
}
