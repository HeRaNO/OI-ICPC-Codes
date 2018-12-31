//Code By HeRaNO
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 205;
string a, b;
int num1[MAXN], num2[MAXN], num3[2 * MAXN];

void work()
{
	int i = 1, j = 1, t = 0;
	num3[0] = max(num1[0], num2[0]);
	for (i = 1; i <= num1[0]; i++)
	{
		t = 0;
		for (j = 1; j <= num2[0]; j++)
		{
			num3[i + j - 1] += num1[i] * num2[j];
			t = num3[i + j - 1];
			num3[i + j - 1] %= 10;
			num3[i + j] += t / 10;
		}
		int k = i + j;
		t = num3[i + j];
		for (k = i + j; num3[k] > 0; k++)
		{
			t = num3[k];
			num3[k] %= 10;
			num3[k + 1] += t / 10;
		}
		num3[0] = max(num3[0], k);
	}
	return ;
}
int main()
{
	int i, len1 = 0, len2 = 0;
	cin >> a;
	len1 = a.size();
	num1[0] = len1;
	for (i = 1; i <= len1; i++)
		num1[i] = a[len1 - i] - '0';
	cin >> b;
	len2 = b.size();
	num2[0] = len2;
	for (i = 1; i <= len2; i++)
		num2[i] = b[len2 - i] - '0';
	if ((num1[1] == 0 && num1[0] == 1) || (num2[1] == 0 && num2[0] == 1))
	{
		printf("0");
		return 0;
	}
	work();
	while (num3[num3[0]] == 0)num3[0]--;
	for (i = num3[0]; i >= 1; i--)
		printf("%d", num3[i]);
	return 0;
}
