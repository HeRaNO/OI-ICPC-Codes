//Code By HeRaNO
#include <cstdio>
using namespace std;

int n, a;
double sum = 0.0;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		sum = sum + double(a);
	}
	printf("%.2lf", sum / double(n));
	return 0;
}
