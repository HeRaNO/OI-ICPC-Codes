#include <cstdio>
using namespace std;

int t1, t2;
int ans;

int main()
{
	scanf("%d %d", &t1, &t2);
	t1--;
	for (int i = 1; i <= t2; i++) ans += (t2 / i);
	for (int i = 1; i <= t1; i++) ans -= (t1 / i);
	printf("%d\n", ans);
	return 0;
}
