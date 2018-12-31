//Code By HeRaNO
#include<cstdio>
using namespace std;
int s;
void pow(int n)
{
	int m = n;
	if (n <= 2)
	{
		if (n != 1) printf("(%d)", n);
		return ;
	}
	if (s != n) printf("(");
	int i, t;
	while (m > 0)
	{
		t = 1;
		i = 0;
		while (t * 2 <= m)
		{
			t *= 2;
			i++;
		}
		m -= t;
		printf("2");
		pow(i);
		if (m != 0) printf("+");
	}
	if (s != n) printf(")");
	return ;
}

int main()
{
	scanf("%d", &s);
	pow(s);
	printf("\n");
	return 0;
}
