#include <cstdio>
using namespace std;

int que[100000];
int n, m, flag;
int i, j, k, ans;
int fro = 1, en, num;
bool ok = false;

int main()
{
	//freopen("translate.in","r",stdin);freopen("translate.out","w",stdout);
	scanf("%d %d", &m, &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &flag);
		ok = false;
		for (j = fro; j <= en; j++)
		{
			if (que[j] == flag)
			{
				ok = true;
				break;
			}
		}
		if (ok) continue;
		if (num == m)
		{
			que[fro] = 0;
			fro++;
			en++;
			que[en] = flag;
			ans++;
		}
		else
		{
			en++;
			que[en] = flag;
			ans++;
			num++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
