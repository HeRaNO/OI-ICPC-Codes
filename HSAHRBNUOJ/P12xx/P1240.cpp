#include<iostream>
#include<cstdio>
using namespace std;
char num[15];
int i, j, k, len, pos;
bool flag = false;
int main()
{
	i = 1;
	while (cin >> num[i])
		i++;
	len = i;
	if (num[1] == '-')
		flag = true;
	len--;
	for (i = len; i >= 1; i--)
		if (num[i] != '0')
		{
			pos = i;
			break;
		}
	if (flag)
	{
		cout << "-";
		for (i = pos; i >= 2; i--) cout << num[i];
	}
	else
	{
		for (i = pos; i >= 1; i--) cout << num[i];
	}
	return 0;
}
