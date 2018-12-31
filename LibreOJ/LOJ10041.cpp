#include <bits/stdc++.h>
#define X 2000000
using namespace std;

const long long M1 = 275593LL;
const long long M2 = 275591LL;

struct Hashlink
{
	long long y;
	int nxt;
};

Hashlink e[X | 1];
int head[M1], cnt;
long long a, b, c, an;

bool check(long long x)
{
	long long m = x % M1, n = x % M2;
	for (int i = head[m]; ~i; i = e[i].nxt)
		if (e[i].y == n) return true;
	e[cnt] = (Hashlink)
	{
		n, head[m]
	};
	head[m] = cnt++;
	return false;
}

int main()
{
	memset(head, -1, sizeof head);
	scanf("%lld %lld %lld", &a, &b, &c);
	an = 1;
	check(an);
	for (int n = 1; n <= X; n++)
	{
		an = ((a * an) % c + an % b) % c;
		if (check(an))
		{
			printf("%d\n", n);
			return 0;
		}
	}
	puts("-1");
	return 0;
}