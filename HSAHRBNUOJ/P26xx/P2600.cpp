#include <cmath>
#include <cstdio>
using namespace std;

long long t;
int k, a, b, m;
int cnt;
bool out;

bool is_prime(int x)
{
	int r = sqrt(x);
	for (int i = 2; i <= r; i++)
		if (!(x % i)) return false;
	return true;
}

int main()
{
	//freopen("czp.in","r",stdin);freopen("czp.out","w",stdout);
	scanf("%d", &k);
	while (k--)
	{
		out = false;
		cnt = 0;
		scanf("%lld %d %d %d", &t, &a, &b, &m);
		if (a == 1) a++;
		for (int i = a; i <= b; i++)
			if (is_prime(i))
			{
				cnt++;
				if (cnt == m)
				{
					out = true;
					printf("%lld\n", (t / i) % i);
					break;
				}
			}
		if (!out) printf("ERR\n");
	}
	return 0;
}
