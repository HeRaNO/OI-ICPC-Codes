#include <cstdio>
int a, b, c;
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", mymax(mymax(a, b), c));
	return 0;
}