#include <cstdio>
using namespace std;

int a[6], k;
bool out;

inline bool judge(int x)
{
	for (int i = 1; i <= 5; i++) a[6 - i] = x % 10, x /= 10;
	if ((a[1] * 100 + a[2] * 10 + a[3]) % k) return false;
	if ((a[2] * 100 + a[3] * 10 + a[4]) % k) return false;
	if ((a[3] * 100 + a[4] * 10 + a[5]) % k) return false;
	return true;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(k);
	for (int i = 10000; i <= 30000; i++)
		if (judge(i))
		{
			printf("%d\n", i);
			out = true;
		}
	if (!out) puts("No");
	return 0;
}