#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	long long m, i, k;
	scanf("%lld", &m);
	k = (int)sqrt(m);
	for (i = 2; i <= k; i++)
		if (m % i == 0) break;
	if (i > k) puts("yes");
	else puts("no");
	return 0;
}
