//Code By HeRaNO
#include <cstdio>
#include <cstdlib>

double work()
{
	char a[10];
	scanf("%s", a);
	switch (a[0])
	{
	case '+':
		return work() + work();
	case '-':
		return work() - work();
	case '*':
		return work() * work();
	case '/':
		return work() / work();
	default:
		return atof(a);
	}
}

int main()
{
	double ans;
	ans = work();
	printf("%lf\n", ans);
	return 0;
}
