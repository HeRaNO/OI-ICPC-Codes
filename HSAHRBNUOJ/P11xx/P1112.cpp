#include <cstdio>
#define MAXN 41
using namespace std;

long long fib[MAXN];
int n;

void per_work()
{
	fib[1] = 1;
	fib[2] = 1;
	for (int i = 3; i <= MAXN; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	return ;
}

int main()
{
	per_work();
	scanf("%d", &n);
	printf("%lld\n", fib[n]);
	return 0;
}
