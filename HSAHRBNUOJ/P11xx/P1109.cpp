#include <cstdio>
using namespace std;
int main()
{
	int n, bai, shi, ge, i, j;
	scanf("%d", &n);
	bai = n / 100;
	i = n % 100;
	shi = i / 10;
	ge = i % 10;
	printf("%d %d %d\n", bai, shi, ge);
	return 0;
}
