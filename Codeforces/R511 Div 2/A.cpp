#include <cstdio>
using namespace std;

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	bool f = false;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch - getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	if (f) x = -x;
	return ;
}

int n;

int main()
{
	read(n);
	if (n % 3 == 0) printf("1 1 %d\n", n - 2);
	else if (n % 3 == 1) printf("1 1 %d\n", n - 2);
	else printf("2 2 %d\n", n - 4);
	return 0;
}