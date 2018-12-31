#include <iostream>
#include <cmath>
using namespace std;

bool zhishu(int a)
{
	long b, i;
	double c;
	c = sqrt(a);
	b = floor(c);
	for (i = 2; i <= b; i++)
		if (a % i == 0)
			return 0;
	return 1;
}

int hwlen(int a)
{
	int k = 1, i = 1;
	while (1)
	{
		k *= 10;
		if (a < k) break;
		i++;
	}
	return i;
}

int huiwen(int k)
{
	int a[10], i = 0, j;
	while (k > 0)
	{
		a[i] = k % 10;
		k /= 10;
		i++;
	}
	for (j = 0; j < i; j++)
		if (a[j] != a[i - j - 1])
			return 0;
	return 1;
}

int extend(int k)
{
	int i, ans = 1;
	for (i = 1; i <= k; i++) ans *= 10;
	return ans;
}

int main()
{
	long long a, b, i;
	cin >> a >> b;
	for (i = a; i <= b; i++)
	{
		if (i == 1) continue;
		if (i == 10) continue;
		if (hwlen(i) % 2 == 0 && i != 11)
		{
			i = extend(hwlen(i));
			continue;
		}
		else if (i % 2 == 0 && i != 2) continue;
		else if (i % 3 == 0 && i != 3) continue;
		else
		{
			if (!huiwen(i)) continue;
			else
			{
				if (!zhishu(i)) continue;
				else cout << i << endl;
			}
		}
	}
	return 0;
}
