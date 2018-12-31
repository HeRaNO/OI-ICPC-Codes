//Code By HeRaNO
#include <cstdio>
#define MAXN 1000010
#define MOD 32767
using namespace std;

int pell[MAXN];
int n, t;

void pre_work()
{
	pell[1] = 1;
	pell[2] = 2;
	for (int i = 3; i <= MAXN; i++)
		pell[i] = (2 * pell[i - 1] + pell[i - 2]) % MOD;
	return ;
}

int main()
{
	pre_work();
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%d\n", pell[n]);
	}
	return 0;
}
