#include <cstdio>
#define MAXN 32
using namespace std;

int T;
long long k;
bool getfish[MAXN];

long long exp(long long base, long long index)
{
	long long sum = 1;
	for (int i = 0; i < index; i++) sum *= base;
	return sum;
}

long long work(long long k)
{
	long long pk = k, res = 0;
	int weishu = 1;
	while (pk)
	{
		pk >>= 1;
		weishu++;
	}
	for (int t = weishu - 1; t >= 0; t--) getfish[t] = k & (1 << t);
	for (int i = 0; i < weishu; i++)
		if (getfish[i])
			res += exp(3, i);
	return res;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld", &k);
		printf("%lld\n", work(k));
	}
	return 0;
}
