//Code By HeRaNO
#include<stdio.h>
int x, k1;
bool judge(int k)
{
	if (k == x) return true;
	if (k > x) return false;
	return judge(k * 2 + 1) || judge(k * 3 + 1);
}
int main()
{
	scanf("%d,%d", &k1, &x);
	if (judge(k1)) printf("YES");
	else printf("NO");
	return 0;
}
