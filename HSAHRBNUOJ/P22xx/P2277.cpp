#include <cstdio>
#include <cstring>
using namespace std;

int prime[350000] = {2};
long long sum, qqq, ppp;
int m, t;
bool number[5000000];
int c;

void hit()
{
	int t;
	memset(number, 0, sizeof(number));
	for (int i = 2; i < 5000000; i++)
	{
		if (number[i]) continue;
		prime[c++] = i;
		t = i + i;
		while (t < 5000000)
		{
			number[t] = 1;
			t += i;
		}
	}
}

int main()
{
	hit();
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &m);
		sum = 1;
		for (int j = 0; j <= c && m != 1; j++)
		{
			qqq = 1;
			if (!number[m])
			{
				qqq = m;
				qqq *= qqq;
				sum *= (qqq - 1) / (m - 1);
				m = 1;
			}
			else
			{
				while (m % prime[j] == 0)
				{
					m /= prime[j];
					qqq *= prime[j];
				}
				qqq *= prime[j];
				sum *= (qqq - 1) / (prime[j] - 1);
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
