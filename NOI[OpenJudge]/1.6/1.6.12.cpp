//Code By HeRaNO
#include <cstdio>
int t[100000];
int i = 1, j, l, n, a, b;
using namespace std;
int main()
{
	scanf("%d", &n);
	t[0] = 2;
	while (i < n)
	{
		t[l] *= 2;
		for (j = l - 1; ~j; j--)
		{
			t[j] *= 2;
			if (t[j] >= 10)
			{
				t[j] -= 10;
				t[j + 1]++;
			}
		}
		i++;
		if (t[l] >= 10)
		{
			t[l] -= 10;
			l++;
			t[l]++;
		}
	}
	for (j = l; ~j; j--) printf("%d", t[j]);
	return 0;
}

