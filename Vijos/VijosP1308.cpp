#include <cstdio>
#include <cstring>
using namespace std;

long long ans[21], now[21];
int dep, num = 0, out_num = 0, ipos;

long long gcd(long long x, long long y)
{
	return y ? gcd(y, x % y) : x;
}

long long mymax(long long x, long long y)
{
	return x > y ? x : y;
}

void print()
{
	for (long long i = 1; ans[i]; i++)
		num++;
	for (long long i = 1; ans[i]; i++)
	{
		out_num++;
		printf("%lld ", ans[i]);
		if (out_num == num - 1)
		{
			ipos = i + 1;
			break;
		}
	}
	for (long long i = ipos; ans[i]; i++)
		printf("%lld", ans[i]);
}

bool dfs(long long a, long long b, int k)
{
	if (k == dep)
	{
		if (a == 1)
		{
			now[k] = b;
			if (now[k] < ans[k] || ans[k] == 0)
				memcpy(ans, now, sizeof(now));
			return true;
		}
		return false;
	}
	bool flag = false;
	long long first = b % a ? b / a + 1 : b / a;
	for (long long i = mymax(now[k - 1] + 1, first);; i++)
	{
		if (b * (dep + 1 - k) <= i * a) break;
		now[k] = i;
		long long x = a * i - b;
		long long y = b * i;
		long long kt = gcd(x, y);
		if (dfs((long long)x / kt, (long long)y / kt, k + 1))
			flag = true;
	}
	return flag;
}
void work(int a, int b)
{
	for (dep = 1;; dep++)
	{
		if (dfs((long long)a, (long long)b, 1))
		{
			print();
			break;
		}
	}
}
int main()
{
	//freopen("data.in","r",stdin);freopen("data.out","w",stdout);
	long long a, b;
	scanf("%lld %lld", &a, &b);
	int kt = gcd(a, b);
	work(a / kt, b / kt);
	return 0;
}