#include <cstdio>
#include <cstring>
#define MAXL 100
using namespace std;

char a[MAXL], b[MAXL];
int alen, blen, len, x, cp;

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}
int mymax(int a, int b)
{
	return a > b ? a : b;
}
int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	while (true)
	{
		scanf("%s", a);
		if (a[0] == '-') break;
		scanf("%s", b);
		alen = strlen(a);
		blen = strlen(b);
		len = alen + blen;
		x = 0;
		for (int i = 0; i < alen; i++)
		{
			cp = 0;
			for (int j = 0, k = i; k < alen, j < blen; j++)
				if (a[k] == b[j]) cp++, k++;
			x = mymax(x, cp);
		}
		x <<= 1;
		int t = gcd(x, len);
		if (!x) printf("appx(%s,%s) = 0\n", a, b);
		else if (x == len) printf("appx(%s,%s) = 1\n", a, b);
		else
		{
			x /= t;
			len /= t;
			printf("appx(%s,%s) = %d/%d\n", a, b, x, len);
		}
	}
	return 0;
}
