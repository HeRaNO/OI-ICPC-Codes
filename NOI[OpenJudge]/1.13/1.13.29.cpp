//Code By HeRaNO
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char st[1001];
int word[1001], ck[130];
int main()
{
	memset(ck, 0, sizeof(ck));
	int i, j, k, len, maxck = 0, maxpos;
	gets(st);
	len = strlen(st);
	for (i = 0; i < len; i++)
	{
		word[i] = st[i];
		ck[word[i]]++;
	}
	for (i = 122; i >= 97; i--)
	{
		if (ck[i] >= maxck)
		{
			maxck = ck[i];
			maxpos = i;
		}
	}
	cout << (char)maxpos << " " << maxck;
}
