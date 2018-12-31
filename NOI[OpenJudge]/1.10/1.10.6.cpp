//Code By HeRaNO
#include <cstdio>
#include <algorithm>
#define MAXN 10
using namespace std;

int even[MAXN], odd[MAXN];
int even_cnt, odd_cnt;
int a;

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		scanf("%d", &a);
		if (a % 2) odd[odd_cnt++] = a;
		else even[even_cnt++] = a;
	}
	sort(odd, odd + odd_cnt);
	sort(even, even + even_cnt);
	for (int i = odd_cnt - 1; ~i; i--) printf("%d ", odd[i]);
	for (int i = 0; i < even_cnt; i++) printf("%d ", even[i]);
	return 0;
}
