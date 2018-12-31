#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	char st[100];
	int i, chang, dotpos;
	gets(st);
	chang = strlen(st);
	for (i = 0; i < chang; i++)
		if (st[i] == '.')
		{
			dotpos = i;
			break;
		}
	int zhengshu[100], xiaoshu[100];
	memset(xiaoshu, 0, sizeof(xiaoshu));
	for (i = 0; i < dotpos; i++) zhengshu[i] = st[i] - 48;
	for (i = 0; i < chang - dotpos - 2; i++) xiaoshu[i] = st[dotpos + i + 1] - 48;
	if (xiaoshu[8] >= 5) xiaoshu[7]++;
	for (i = 0; i < dotpos; i++) cout << zhengshu[i];
	cout << '.';
	for (i = 0; i <= 7; i++) cout << xiaoshu[i];
	cout << endl;
	return 0;
}
