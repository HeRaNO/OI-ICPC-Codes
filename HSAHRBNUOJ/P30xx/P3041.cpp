#include <cstdio>
using namespace std;
int step, n;
int main()
{
	scanf("%d", &n);
	while (n != 1)
	{
		step++;
		if (!(n & 1)) n >>= 1;
		else n = n * 3 + 1;
	}
	printf("%d\n", step);
	return 0;
}