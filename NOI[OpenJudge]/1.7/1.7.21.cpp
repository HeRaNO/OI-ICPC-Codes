//Code By HeRaNO
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 110
using namespace std;

char s[MAXN], from[MAXN], to[MAXN];
string a[MAXN];
int len, cnt = 1;
int wordcnt;

int main()
{
	gets(s);
	gets(from);
	gets(to);
	len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] != ' ' && s[i + 1] != ' ')
			a[cnt] += s[i];
		else if (s[i] != ' ')
		{
			a[cnt] += s[i];
			cnt++;
		}
	}
	for (int i = 1; i <= cnt; i++)if (a[i] == from) a[i] = to;
	for (int i = 1; i <= cnt; i++)cout << a[i] << ' ';
	return 0;
}
