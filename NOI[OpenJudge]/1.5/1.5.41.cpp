//Code By HeRaNO
#include<cstdio>
using namespace std;
int n, m, ans;
void work(int a)
{
	while (a)
	{
		if (a % 10 == 2) ans++;
		a /= 10;
	}
	return ;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = n; i <= m; i++)
		work(i);
	printf("%d", ans);
	return 0;
}
