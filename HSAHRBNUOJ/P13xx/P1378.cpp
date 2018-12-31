#include <cstdio>
using namespace std;

int n, s;
int ans;

int main()
{
	//freopen("flower.in","r",stdin);freopen("flower.out","w",stdout);
	scanf("%d", &n);
	if (n & 1)
	{
		s = (n - 1) / 2;
		ans = n * (s * (s - 1) / 2);
		printf("%d\n", ans);
	}
	else
	{
		s = n / 2;
		ans = s * (((s * 2 - 2) * (s - 1)) / 2);
		printf("%d\n", ans);
	}
	return 0;
}
