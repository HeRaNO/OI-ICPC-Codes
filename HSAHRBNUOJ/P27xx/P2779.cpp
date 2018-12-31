#include <cstdio>
using namespace std;

double ans;
int n;

int main()
{
	//freopen("collecting.in","r",stdin);freopen("collecting.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) ans = ans + (1 / (double)i);
	ans = ans * double(n);
	printf("%.4lf\n", ans);
	return 0;
}
