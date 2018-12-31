#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct milk
{
	int price;
	long v;

};

bool comp(const milk &a, const milk &b)
{
	return a.price < b.price;
}

milk a[5001];
int need;
int farmer;
int i, flag;
long long ans, buy;

int main()
{
	scanf("%d %d", &need, &farmer);
	for (i = 1; i <= farmer; i++)
		scanf("%d %ld", &a[i].price, &a[i].v);
	sort(a + 1, a + farmer + 1, comp);
	for (i = 1;; i++)
	{
		ans += a[i].price * a[i].v;
		buy += a[i].v;
		if (buy >= need)
		{
			flag = i;
			break;
		}
	}
	long long tmp = buy - need;
	if (tmp == 0) printf("%lld\n", ans);
	else
	{
		long long tmp1 = tmp * a[flag].price;
		printf("%lld\n", ans - tmp1);
	}
	return 0;
}
