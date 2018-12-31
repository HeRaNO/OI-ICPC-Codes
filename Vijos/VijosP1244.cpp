#include <cstdio>
#include <cstring>
#define MAXN 90000000
using namespace std;

char passage[MAXN];
int len, t, tt, r = 4;
int cnt[128];
char a;
int pass[26];

bool islow(char a)
{
	if (a >= 'a' && a <= 'z') return true;
	return false;
}

bool isup(char a)
{
	if (a >= 'A' && a <= 'Z') return true;
	return false;
}

int main()
{
	while (~scanf("%c", &a))
	{
		passage[len++] = a;
		if (a >= 'a' && a <= 'z') a -= 32;
		if (a < 'A' || a > 'Z') continue;
		cnt[a]++;
	}
	for (int i = 65; i <= 90; i++)
		if (t < cnt[i])
		{
			t = cnt[i];
			tt = i - 65;
		}
	pass[tt] = r;
	for (int i = tt + 1; i <= 25; i++)
	{
		r = (r + 1) % 26;
		pass[i] = r;
	}
	for (int i = 0; i < tt; i++)
	{
		r = (r + 1) % 26;
		pass[i] = r;
	}
	for (int i = 0; i < len; i++)
	{
		if (isup(passage[i])) printf("%c", pass[passage[i] - 'A'] + 'A');
		else if (islow(passage[i])) printf("%c", pass[passage[i] - 'a'] + 'a');
		else printf("%c", passage[i]);
	}
	return 0;
}
