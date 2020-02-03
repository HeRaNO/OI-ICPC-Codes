#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 100000
bool once[MAXN];
int prime[10000], k = 0;
void get()
{
	int i, j;
	memset(once, 1, sizeof(once));
	for (i = 2; i < MAXN; i++)
	{
		if (once[i])
		{
			prime[k++] = i;
			j = i;
			while (j + i < MAXN)
			{
				j += i;
				once[j] = 0;
			}
		}
	}
	once[0] = once[1] = 0;
	return;
}
int main()
{
	int n, m1, m2, nfac, i, s, si, ans, maxs, temp;
	int fac[100], facexp[100];
	get();
	scanf("%d%d%d", &n, &m1, &m2);
	nfac = 0;
	for (i = 0; prime[i]*prime[i] <= m1; i++)
		if (m1 % prime[i] == 0)
		{
			s = 0;
			while (m1 % prime[i] == 0)
			{
				s++;
				m1 /= prime[i];
			}
			fac[nfac] = prime[i];
			facexp[nfac] = s;
			nfac++;
		}
	if (m1 > 1)
	{
		fac[nfac] = m1;
		facexp[nfac] = 1;
		nfac++;
	}
	ans = 999999999;
	for (i = 0; i < nfac; i++) facexp[i] *= m2;
	while (n--)
	{
		cin >> si;
		maxs = 0;
		for (i = 0; i < nfac; i++)
			if (si % fac[i] != 0)
			{
				maxs = 999999999;
				break;
			}
			else
			{
				s = 0;
				while (si % fac[i] == 0)
				{
					s++;
					si /= fac[i];
				}
				if (facexp[i] % s == 0) temp = facexp[i] / s;
				else temp = facexp[i] / s + 1;
				if (temp > maxs) maxs = temp;
			}
		if (maxs < ans) ans = maxs;
	}
	if (ans == 999999999) ans = -1;
	printf("%d", ans);
	return 0;
}