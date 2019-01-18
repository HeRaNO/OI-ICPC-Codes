#include <cstdio>

int main()
{
	int a,b;
	while (scanf("%d %d",&a,&b))
	{
		if (!a&&!b) break;
		printf("%d\n",(b/3)-((a-1)/3));
	}
	return 0;
}
