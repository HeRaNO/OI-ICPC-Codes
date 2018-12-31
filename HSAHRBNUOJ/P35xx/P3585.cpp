#include <cstdio>
#include <cstring>
using namespace std;

int n, T, R, L, mod, now;
long long ans;

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int getdigit(int x)
{
	int res = 0;
	while (x)
	{
		x /= 10;
		res++;
	}
	return res;
}

int _10pow(int x)
{
	int res = 1;
	for (int i = 1; i <= x; i++) res = res * 10;
	return res;
}

int main()
{
	read(T);
	while (T--)
	{
		ans = 0LL;
		read(L);
		read(R);
		n = getdigit(L);
		mod = _10pow(n - 1);
		for (int i = L; i <= R; i++)
		{
			now = i;
			now = (now % mod) * 10 + (now / mod);
			while (now != i)
			{
				if (now >= L && now <= R && now > i) ans++;
				now = (now % mod) * 10 + (now / mod);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
