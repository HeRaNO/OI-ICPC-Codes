#include <cstdio>
using namespace std;

long long a, b;

int main()
{
	//freopen("math.in","r",stdin);freopen("math.out","w",stdout);
	scanf("%lld %lld", &a, &b);
	printf("%lld\n", a * b - a - b);
	return 0;
}