//Code By HeRaNO
#include <cstdio>
using namespace std;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", mymax(a, mymax(b, c)));
	return 0;
}