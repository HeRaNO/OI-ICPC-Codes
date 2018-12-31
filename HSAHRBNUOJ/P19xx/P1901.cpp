#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int a = 10, b;
	char st[1000];
	long i, j, len;
	cin >> st;
	cin >> b;
	len = strlen(st);
	int q[1000];
	long long ten = 0;
	if (st[0] == '0')
	{
		cout << "0" << endl;
		return 0;
	}
	else
	{
		for (i = 0; i < len; i++)
		{
			if ((st[i] >= '0') && (st[i] <= '9')) q[i] = st[i] - 48;
			else if (st[i] == 'A' || st[i] == 'a') q[i] = 10;
			else if (st[i] == 'B' || st[i] == 'b') q[i] = 11;
			else if (st[i] == 'C' || st[i] == 'c') q[i] = 12;
			else if (st[i] == 'D' || st[i] == 'd') q[i] = 13;
			else if (st[i] == 'E' || st[i] == 'e') q[i] = 14;
			else if (st[i] == 'F' || st[i] == 'f') q[i] = 15;
		}
		for (i = 0; i < len; i++)
			ten = ten + q[i] * round(pow(a, len - 1 - i));
		i = 0;
		while (ten != 0)
		{
			q[i] = ten % b;
			ten = ten / b;
			i++;
		}
		for (j = i - 1; j >= 0; j--)
		{
			if ((q[j] >= 0) && (q[j] <= 9)) cout << q[j];
			else if (q[j] == 10) cout << 'A';
			else if (q[j] == 11) cout << 'B';
			else if (q[j] == 12) cout << 'C';
			else if (q[j] == 13) cout << 'D';
			else if (q[j] == 14) cout << 'E';
			else if (q[j] == 15) cout << 'F';
		}
		cout << endl;
		return 0;
	}
}
