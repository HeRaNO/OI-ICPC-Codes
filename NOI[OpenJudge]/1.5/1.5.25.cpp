//Code By HeRaNO
#include<cstdio>
using namespace std;
int n[3];
int main()
{
	for (n[0] = 0; n[0] < 8; n[0]++)
		for (n[1] = 0; n[1] < 8; n[1]++)
			for (n[2] = 0; n[2] < 8; n[2]++)
			{
				int x = n[0] * 7 * 7 + n[1] * 7 + n[2];
				int y = n[2] * 9 * 9 + n[1] * 9 + n[0];
				if (x == y && y == 0) continue;
				if (x == y)
				{
					printf("%d\n", x);
					printf("%d%d%d\n", n[0], n[1], n[2]);
					printf("%d%d%d\n", n[2], n[1], n[0]);
					return 0;
				}
			}
	return 0;
}
