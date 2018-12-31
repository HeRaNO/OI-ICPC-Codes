//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXN 1000000
using namespace std;
int cnt;
int pri[MAXN];
bool isPrimes[MAXN];
void FilterPrime()
{
	for (int j = 2; j <= 1000000; j++)
	{
		if (isPrimes[j])
		{
			pri[++cnt] = j;
			for (int m = 2; j * m <= 1000000; m++)
				isPrimes[j * m] = false;
		}
	}
}
int main()
{
	memset(isPrimes, true, sizeof(isPrimes));
	int n;
	scanf("%d", &n);
	FilterPrime();
	printf("%d\n", pri[n]);
	return 0;
}
