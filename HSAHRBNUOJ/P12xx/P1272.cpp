#include <cstdio>
#define MAXN 10010
using namespace std;

struct solution
{
	int m;
	long long mz;
	solution() {}
	solution(int _m, long long _o): m(_m), mz(_o) {}
};

solution a[MAXN];
int m, o, opt, T, now, nm;
long long nmz;

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'P')
		{
			x = 0;
			return ;
		}
		if (ch == 'Z')
		{
			x = 1;
			return ;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(m);
	read(o);
	read(T);
	a[++now] = solution(m, m * o);
	while (T--)
	{
		read(opt);
		if (!opt)
		{
			read(m);
			read(o);
			nm = a[now].m + (long long)m;
			nmz = a[now].mz + 1LL * m * o;
			a[++now] = solution(nm, nmz);
		}
		else
		{
			if (now - 1) now--;
		}
		printf("%d %.5lf\n", a[now].m, (double)a[now].mz / (double)a[now].m);
	}
	return 0;
}