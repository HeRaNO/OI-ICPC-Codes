//Code By HeRaNO
#include <cstdio>
using namespace std;
unsigned long long f[50];
int n;
int main()
{
	scanf("%d", &n);
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= n; i++)
		f[i] = f[i - 1] + f[i - 2];
	printf("%llu", f[n]);
	return 0;
}
