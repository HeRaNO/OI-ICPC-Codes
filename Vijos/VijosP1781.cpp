#include <cstdio>
using namespace std;

long long a, m;
long long x, y;

void ex_gcd(long long a, long long b, long long &x, long long &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return ;
	}
	else
	{
		ex_gcd(b, a % b, x, y);
		long long tmp = x;
		x = y;
		y = tmp - (a / b) * y;
	}
}


int main()
{
	//freopen("mod.in","r",stdin);freopen("mod.out","w",stdout);
	scanf("%I64d %I64d", &a, &m);
	ex_gcd(a, m, x, y);
	printf("%I64d", (x + m) % m);
	return 0;
}