#include <cstdio>
#include <cstring>
#include <ctime>
#define MAXN 100010
using namespace std;

int n, t, cnt;
bool gang[MAXN];

int main()
{
	//freopen("resist.in","r",stdin);freopen("resist.out","w",stdout);
	memset(gang, false, sizeof(gang));
	scanf("%d %d", &n, &t);
	for (int i = 1, j = 0;; i++)
	{
		if (!gang[i])
		{
			j++;
			if (j == t)
			{
				gang[i] = true;
				j = 0;
				cnt++;
			}
			if (cnt == n)
			{
				printf("%d\n", i);
				return 0;
			}
		}
		if (i == n) i = 0;
	}
	return 0;
}
