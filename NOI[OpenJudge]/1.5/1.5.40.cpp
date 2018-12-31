//Code By HeRaNO
#include<cstdio>
using namespace std;
int n, ans;
void work(int a)
{
	while (a)
	{
		if (a % 10 == 1) ans++;
		a /= 10;
	}
	return ;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		work(i);
	printf("%d", ans);
	return 0;
}
