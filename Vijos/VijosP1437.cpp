#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	char *s = new char[72 * (n / 72 + 1) + 1];
	char *temp = new char[73];
	for (int i = 0; i <= n / 72; i++)
	{
		scanf("%s", temp);
		memcpy(s + i * 72, temp, 72);
	}
	long long a = 0, b = 1, k = 0;
	bool flag = false;
	while (!flag)
	{
		if (s[(a + k) % n] > s[(b + k) % n])
			a += k + 1;
		else if (s[(a + k) % n] < s[(b + k) % n])
			b += k + 1;
		if (a == b)
			b += 1;
		k = 0;
		while (s[(a + k) % n] == s[(b + k) % n])
		{
			if (k == n)
			{
				flag = true;
				break;
			}
			k++;
		}
	}
	printf("%d\n", min(a, b));
	return 0;
}
