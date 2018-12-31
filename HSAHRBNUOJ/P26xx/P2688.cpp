#include <cstdio>
#include <cstring>
using namespace std;

int n, t;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%d\n", n * (n - 1));
	}
	return 0;
}
