#include <cstdio>
using namespace std;

int a[8], T;
unsigned long long ans;
bool f;

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

inline void read(unsigned long long &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3LL) + (x << 1LL) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(T);
	while (T--)
	{
		f = true;
		for (int i = 0; i < 8; i++)
		{
			read(a[i]);
			if (a[i] != 60) f = false;
		}
		read(ans);
		if (f && ans == (1LL << 63)) puts("18446744073709551616");
		else
		{
			for (int i = 0; i < 8; i++) ans += 1LL << a[i];
			printf("%llu\n", ans);
		}
	}
	return 0;
}