#include <cstdio>
#include <cstdlib>
#define MAXN 100010
using namespace std;

struct toy
{
	bool sta;
	char name[15];
};

toy a[MAXN];
int n, T, pos;
int st, s;

int main()
{
	//freopen("toy.in","r",stdin);freopen("toy.out","w",stdout);
	scanf("%d %d", &n, &T);
	for (int i = n - 1; ~i; i--) scanf("%d %s", &a[i].sta, a[i].name);
	pos = n - 1;
	while (T--)
	{
		scanf("%d %d", &st, &s);
		if (!a[pos].sta)
		{
			if (!st)
				pos = (pos + s) % n;
			else
				pos = (pos - s + n) % n;
		}
		else
		{
			if (!st)
				pos = (pos - s + n) % n;
			else
				pos = (pos + s) % n;
		}
	}
	printf("%s\n", a[pos].name);
	return 0;
}
