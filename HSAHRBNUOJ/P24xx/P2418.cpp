#include <cstdio>
#include <cstdlib>
using namespace std;

char t[11], ans;

int len(int x)
{
	if (x < 10) return 1;
	else if (x < 100) return 2;
	else if (x < 1000) return 3;
	else if (x < 10000) return 4;
	else if (x < 100000) return 5;
	else if (x < 1000000) return 6;
	else if (x < 10000000) return 7;
	else if (x < 100000000) return 8;
	else if (x < 1000000000) return 9;
}

int main()
{
	int n, i = 1;
	scanf("%d", &n);
	int tmp = 1;
	while (1)
	{
		if (n <= tmp) break;
		n -= tmp;
		i++;
		tmp = len(i);
	}
	sprintf(t, "%d", i);
	printf("%c", t[n - 1]);
	return 0;
}
