#include <iostream>
#include <cstring>
using namespace std;
char s1[1500], s2[1500];
char *ss = new char[3000];
void plusS()
{
	int l1 = strlen(s1) - 1, l2 = strlen(s2) - 1;
	bool big = l1 > l2;
	int pos = big ? l1 + 1 : l2 + 1;
	int p = pos;
	while (l1 >= 0 || l2 >= 0)
	{
		if (l1 >= 0 && l2 >= 0)
			ss[p] = s1[l1] + s2[l2];
		else if (big)
			ss[p] = s1[l1] + '0';
		else if (l2 > l1)
			ss[p] = s2[l2] + '0';
		l1--;
		l2--;
		p--;
	}
	for (p = pos; p > 0; p--)
	{
		if (ss[p - 1] != '\0')
			ss[p - 1] -= '0';
		ss[p - 1] += char(int(ss[p] - '0' - '0') / 10) + '0';
		ss[p] = char(int(ss[p] - '0' - '0') % 10) + '0';
	}
	ss[pos + 1] = '\0';
}
int main()
{
	char s[1500];
	int plus[1500] = { 0 };
	int i = 0, j = 0;
	while (cin.get(s[i]))
	{
		if (s[i] == '\n')
		{
			s[i] = 0;
			break;
		}
		if (s[i] == '+')
		{
			plus[j] = i;
			j++;
		}
		i++;
	}
	if (j == 0)
	{
		cout << s << endl;
		return 0;
	}
	int pos = plus[0];
	memset(s1, 0, sizeof(s1));
	memset(s2, 0, sizeof(s2));
	memset(ss, 0, sizeof(ss));
	memcpy(s1, s, pos);
	for (j = 1; plus[j] != 0; j++)
	{
		memcpy(s2, s + pos + 1, plus[j] - pos - 1);
		plusS();
		memset(s1, 0, sizeof(s1));
		memset(s2, 0, sizeof(s2));
		memcpy(s1, ss, strlen(ss));
		memset(ss, 0, sizeof(ss));
		pos = plus[j];
	}
	memcpy(s2, s + pos + 1, strlen(s) - pos - 1);
	plusS();
	pos = 0;
	while (ss[pos] == '0' || ss[pos] == '\0') pos++;
	ss += pos;
	cout << ss << endl;
	ss -= pos;
	delete[] ss;
	return 0;
}
