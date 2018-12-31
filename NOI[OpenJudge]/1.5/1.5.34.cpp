//Code By HeRaNO
#include <cstdio>
using namespace std;

int biao[13] = {0, 1, 3, 9, 33, 153, 873, 5913, 46233, 409113, 4037913, 43954713, 522956313};
int n;

int main()
{
	scanf("%d", &n);
	printf("%d", biao[n]);
}
